PORTNAME=	camlidl
DISTVERSION=	1.12
CATEGORIES=	lang
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	kennedy.greg@gmail.com
COMMENT=	Stub code generator for using C/C++ libraries from OCaml
WWW=		https://caml.inria.fr/pub/old_caml_site/camlidl/

LICENSE=	LGPL20 LGPL21
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake ocaml
USE_GITHUB=	yes
GH_ACCOUNT=	xavierleroy
GH_TAGNAME=	${PORTNAME}${DISTVERSION:S/.//}

MAKE_JOBS_UNSAFE=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}

OPTIONS_DEFINE=		DOCS
DOCS_BUILD_DEPENDS=	hevea>=0:textproc/hevea

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-patch:
	@${LN} -sf ${WRKSRC}/config/Makefile.unix ${WRKSRC}/config/Makefile

do-build-DOCS-on:
	cd ${WRKSRC}/doc && ${SETENVI} ${MAKE_ENV} ${MAKE_CMD} \
		tools/transf tools/texquote2 ../docs/index.html
	${RM} ${WRKSRC}/docs/main.haux ${WRKSRC}/docs/main.htoc

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${OCAML_LIBDIR}/caml \
		${STAGEDIR}${PREFIX}/${OCAML_LIBDIR}/stublibs

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/htmlman

do-test:
	@${ECHO_CMD} "Testing IDL library"
	cd ${WRKSRC}/tests && ${SETENVI} ${MAKE_ENV} ${MAKE_CMD} all

.include <bsd.port.mk>
