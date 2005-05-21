# ex:ts=8
# Ports collection makefile for:	ocaml-sdl
# Date created:			Jun 1, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sdl
PORTVERSION=	0.7.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ocamlsdl
PKGNAMEPREFIX=	ocaml-
DISTNAME=	ocamlsdl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OCaml interface to the SDL

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib \
		lablgl:${PORTSDIR}/graphics/ocaml-lablgl

BROKEN=		Changes permissions of installed file

USE_SDL=	sdl ttf image mixer
USE_AUTOCONF_VER=259
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-findlib
USE_GMAKE=	yes

PKGDEINSTALL=	${PKGINSTALL}

.if !defined(NOPORTDOCS)
PORTDOCS=	*

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
.endif

post-install:
	@${FIND} ${PREFIX}/lib/ocaml/site-lib/sdl ! -type d | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm lib/ocaml/site-lib/${PORTNAME}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ocamlfind remove ${PORTNAME} 2>/dev/null || true" >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/html/ ${DOCSDIR}
.endif

.include <bsd.port.mk>
