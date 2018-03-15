# Created by: ijliao
# $FreeBSD$

PORTNAME=	findlib
PORTVERSION=	1.7.1
CATEGORIES=	devel
MASTER_SITES=	http://download.camlcity.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	OCaml package manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_OCAML=	yes
USE_OCAML_CAMLP4=yes
USE_OCAML_FINDLIB=yes
OCAMLFIND_DEPEND=	# Avoid dependency loop
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-bindir "${PREFIX}/bin" -mandir "${PREFIX}/man" \
		-sitelib "${PREFIX}/${OCAML_SITELIBDIR}" \
		-config "${PREFIX}/etc/findlib.conf"
MAKE_ENV=	OCAML_LIBDIR="${PREFIX}/${OCAML_LIBDIR}"
ALL_TARGET=	all opt
MAKE_JOBS_UNSAFE=	yes
DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	TOOLBOX DOCS
OPTIONS_DEFAULT=TOOLBOX
OPTIONS_SUB=	yes
TOOLBOX_DESC=	Include toolbox interface (requires OCaml with TK)
TOOLBOX_CONFIGURE_ON=	-with-toolbox
TOOLBOX_RUN_DEPENDS=	labltk:x11-toolkits/ocaml-labltk
TOOLBOX_BUILD_DEPENDS=	${TOOLBOX_RUN_DEPENDS}

post-install:
	cd ${STAGEDIR}${PREFIX} && \
	    ${STRIP_CMD} bin/ocamlfind \
	    ${OCAML_SITELIBDIR}/findlib/findlib.cmxs \
	    ${OCAML_SITELIBDIR}/findlib/findlib_dynload.cmxs \
	    ${OCAML_SITELIBDIR}/findlib/findlib_top.cmxs

post-install-TOOLBOX-on:
	${CHMOD} 755 ${STAGEDIR}${PREFIX}/bin/ocamlfind \
	    ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/findlib/make_wizard

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR} \
	    "! -regex .*ref-man.*"

.include <bsd.port.mk>
