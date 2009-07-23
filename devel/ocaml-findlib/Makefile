# ex:ts=8
# Ports collection makefile for:	findlib
# Date created:			Jul 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	findlib
PORTVERSION=	1.2.4
CATEGORIES=	devel
MASTER_SITES=	http://download.camlcity.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	johans@stack.nl
COMMENT=	OCaml package manager

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml
RUN_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	all opt

CONFIGURE_ARGS=	-bindir "${PREFIX}/bin" -mandir "${PREFIX}/man" \
		-sitelib "${PREFIX}/lib/ocaml/site-lib" \
		-config "${PREFIX}/etc/findlib.conf"

DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}

PATTERN=	[[:space:]]*(do|then)?[[:space:]]*)cp([[:space:]]

MAN1=	ocamlfind.1
MAN5=	META.5 findlib.conf.5 site-lib.5

.if !exists(${LOCALBASE}/lib/ocaml/site-lib/labltk)
WITHOUT_TK=	yes
.endif

.if defined(WITHOUT_TK)
PLIST_SUB+=	TK="@comment "
.else
PLIST_SUB+=	TK=""
.endif

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,(${PATTERN}+.*INSTALLDIR),\1\$${BSD_INSTALL_DATA} \3,' \
		-e 's,(${PATTERN}+.*FIND_BIN),\1\$${BSD_INSTALL_SCRIPT} \3,' \
		-e 's,(${PATTERN}+.*LIBBIN),\1\$${BSD_INSTALL_SCRIPT} \3,' \
		-e 's,(${PATTERN}+.*FIND_CONF),\1\$${BSD_INSTALL_DATA} \3,' \
		-e 's,(${PATTERN}+.*SITELIB),\1\$${BSD_INSTALL_DATA} \3,' \
		${WRKSRC}/Makefile ${WRKSRC}/src/findlib/Makefile \
		${WRKSRC}/src/findlib-toolbox/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${DOCSDIR} \
	"! -regex .*ref-man.*")
.endif

.include <bsd.port.mk>
