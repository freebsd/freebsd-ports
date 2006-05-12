# New ports collection makefile for:	ocaml libmagic(3)
# Date created:		Fri May 12 12:52:15 UTC 2006
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	magic
PORTVERSION=	0.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}
PKGNAMEPREFIX=	ocaml-
DISTNAME=	OCaml-Magic-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	An OCaml binding for libmagic(3)

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

ALL_TARGET=	opt
INSTALL_TARGET=	install-opt
USE_GMAKE=	yes

# This really is overzealous but I work this way
.if !exists(/usr/lib/libmagic.so)
LIB_DEPENDS+=	magic:${PORTSDIR}/sysutils/file
.endif

.ifndef(NOPORTDOCS)
ALL_TARGET+=	doc
INSTALL_TARGET+=	install-doc

PORTDOCS=	*
.endif

LIB_STUB_FILES=	\
		dllmagic_stub.so

post-configure:
# LIB safeness
	${REINPLACE_CMD} -E \
		-e's|(-lmagic[[:space:]]+)|\1 -lz |' \
		${WRKSRC}/Makefile
# CFLAGS,PREFIX safeness
	@${REINPLACE_CMD} -E \
		-e 's|^PREFIX.+$$||' \
		-e 's|\$$\(shell[[:space:]]+ocamlc[[:space:]]+-version\)||' \
		-e 's|^(DOCDIR).*$$|\1 = ${DOCSDIR}|' \
		-e 's,^((OCAMLC|OCAMLOPT|OCAMLDEP|OCAMLDOC|OCAMLMKLIB)[^=]*)[[:space:]]*=[[:space:]]*(.+)$$,\1 = ${LOCALBASE}/bin/\3,' \
		${WRKSRC}/Makefile.config

post-install:
# stub files
	@${MKDIR} ${PREFIX}/lib/ocaml/stublibs
.for file in ${LIB_STUB_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/ocaml/stublibs
.endfor

.include <bsd.port.pre.mk>

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.post.mk>
