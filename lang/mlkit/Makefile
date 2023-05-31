PORTNAME=	mlkit
DISTVERSIONPREFIX=	v
DISTVERSION=	4.7.3
CATEGORIES=	lang

MAINTAINER=	serpent7776@gmail.com
COMMENT=	Standard ML compiler
WWW=		https://elsman.com/mlkit/

LICENSE=	GPLv2 MIT HPND BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_NAME_HPND=	Historical Permission Notice and Disclaimer
LICENSE_FILE_GPLv2=	${WRKSRC}/doc/license/GPL-LICENSE
LICENSE_FILE_HPND=	${WRKSRC}/doc/license/MLton-LICENSE
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/doc/license/MLton-LICENSE
LICENSE_PERMS_HPND=	${_LICENSE_PERMS_DEFAULT}

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Code generator supports only x86_64

BUILD_DEPENDS=	bash:shells/bash mlton:lang/mlton
LIB_DEPENDS=	libgmp.so:math/gmp

USES=	gmake autoreconf
USE_GCC=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	melsman
GNU_CONFIGURE=	yes
CONFIGURE_SHELL=	bash

ALL_TARGET=	mlkit mlkit_basislibs
TEST_TARGET=	test
TEST_ENV=	SML_LIB=${STAGEDIR}${PREFIX}/lib/mlkit

PORTDOCS=	mlkit.pdf mllex.pdf mlyacc.pdf NEWS.md

OPTIONS_DEFINE=	DOCS TEST
OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} 's|gcc|${CC}|g' ${WRKSRC}/src/Common/Flags.sml
	@${REINPLACE_CMD} 's|"gcc|"${CC}|g' ${WRKSRC}/src/Compiler/Backend/X64/ExecutionX64.sml
	@${REINPLACE_CMD} "s|FLAGS=-no_gc -par|FLAGS=-no_gc -par -cc '${CC} -Wl,--allow-multiple-definition'|g" ${WRKSRC}/test/parallelism/Makefile
	@${REINPLACE_CMD} "s|^DATE=.*|DATE=2023-05-22|" ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} "s|^COMMITDATE=.*|COMMITDATE=2023-05-22|" ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} "s|^GITVERSION=.*|GITVERSION=\"${PKGVERSION} built by FreeBSD ports, maintained by ${MAINTAINER}\"|" ${WRKSRC}/configure.ac

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mlkit
	${FIND} ${STAGEDIR}${PREFIX}/lib/mlkit/basis -name \*.log -delete
	${RM} -r ${STAGEDIR}${DOCSDIR}/license

.include <bsd.port.mk>
