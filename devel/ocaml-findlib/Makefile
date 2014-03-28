# Created by: ijliao
# $FreeBSD$

PORTNAME=	findlib
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.camlcity.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	johans@FreeBSD.org
COMMENT=	OCaml package manager

USE_OCAML=	yes
HAS_CONFIGURE=	yes
USES=		gmake
ALL_TARGET=	all opt

CONFIGURE_ARGS=	-bindir "${PREFIX}/bin" -mandir "${PREFIX}/man" \
		-sitelib "${PREFIX}/${OCAML_SITELIBDIR}" \
		-config "${PREFIX}/etc/findlib.conf"

OPTIONS_DEFINE=	TOOLBOX
OPTIONS_DEFAULT=TOOLBOX
OPTIONS_SUB=	yes
TOOLBOX_DESC=	Include toolbox interface (requires OCaml with TK)
TOOLBOX_CONFIGURE_ON=	-with-toolbox

MAKE_JOBS_UNSAFE=	yes

DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,path="@SITELIB@,&:${PREFIX}/${OCAML_LIBDIR},' \
		${WRKSRC}/findlib.conf.in

post-install:
.if ${PORT_OPTIONS:MTOOLBOX}
	@${CHMOD} 755 ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/findlib/make_wizard
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR} \
		"! -regex .*ref-man.*"
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ocamlfind

.include <bsd.port.mk>
