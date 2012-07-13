# ex:ts=8
# Ports collection makefile for:	findlib
# Date created:			Jul 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	findlib
PORTVERSION=	1.3.3
CATEGORIES=	devel
MASTER_SITES=	http://download.camlcity.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	johans@FreeBSD.org
COMMENT=	OCaml package manager

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml
RUN_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

MAKE_JOBS_UNSAFE=	yes

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	all opt

CONFIGURE_ARGS=	-bindir "${PREFIX}/bin" -mandir "${PREFIX}/man" \
		-sitelib "${PREFIX}/lib/ocaml/site-lib" \
		-config "${PREFIX}/etc/findlib.conf"

OPTIONS_DEFINE=	TOOLBOX
OPTIONS_DEFAULT=TOOLBOX
TOOLBOX_DESC=	Include toolbox interface (requires OCaml with TK)

DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}

PATTERN=	[[:space:]]*(do|then)?[[:space:]]*)cp([[:space:]]

MAN1=	ocamlfind.1
MAN5=	META.5 findlib.conf.5 site-lib.5

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,(${PATTERN}+.*INSTALLDIR),\1\$${BSD_INSTALL_DATA} \3,' \
		-e 's,(${PATTERN}+.*FIND_BIN),\1\$${BSD_INSTALL_SCRIPT} \3,' \
		-e 's,(${PATTERN}+.*LIBBIN),\1\$${BSD_INSTALL_SCRIPT} \3,' \
		-e 's,(${PATTERN}+.*FIND_CONF),\1\$${BSD_INSTALL_DATA} \3,' \
		-e 's,(${PATTERN}+.*SITELIB),\1\$${BSD_INSTALL_DATA} \3,' \
		${WRKSRC}/Makefile ${WRKSRC}/src/findlib/Makefile \
		${WRKSRC}/src/findlib-toolbox/Makefile
	@${REINPLACE_CMD} \
		-e 's,path="@SITELIB@,&:${PREFIX}/lib/ocaml,' \
		${WRKSRC}/findlib.conf.in

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTOOLBOX} && \
	exists(${LOCALBASE}/bin/ocaml) && \
	!exists(${LOCALBASE}/lib/ocaml/labltk)
IGNORE=		either build OCaml with TK support or disable TOOLBOX
.endif

.if ${PORT_OPTIONS:MTOOLBOX}
CONFIGURE_ARGS+=-with-toolbox
PLIST_SUB+=	TK=""
.else
PLIST_SUB+=	TK="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${DOCSDIR} \
	"! -regex .*ref-man.*")
.endif
.if ${PORT_OPTIONS:MTOOLBOX}
	@${CHMOD} +x ${PREFIX}/lib/ocaml/site-lib/findlib/make_wizard
.endif

.include <bsd.port.mk>
