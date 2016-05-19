# Created by: Thomas Zander <riggs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	embb
PORTVERSION=	0.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	C/C++ library for parallel programming

LICENSE=	BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	siemens

USES=		cmake:outsource compiler:c11

CMAKE_ARGS=	-DINSTALL_PREFIX=${PREFIX}

OPTIONS_DEFINE=	DOCS EXAMPLES TESTS

TESTS_DESC=	Build and run parallel unit tests

DOCS_CMAKE_OFF=	-DINSTALL_DOCS=OFF

TESTS_CMAKE_OFF=-DBUILD_TESTS=OFF

OPTIONS_SUB=	yes

ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.options.mk>

post-patch:
	${RM} ${WRKSRC}/doc/examples/CMakeLists.txt
	${MV} ${WRKSRC}/doc/examples ${WRKSRC}
	${REINPLACE_CMD} -e \
		's|$${INSTALL_PREFIX_DOCS} PARENT_SCOPE|"${DOCSDIR}" PARENT_SCOPE|' \
		${WRKSRC}/CMakeCommon/SetInstallPaths.cmake

.if ${PORT_OPTIONS:MTESTS}
post-build:
	(cd ${BUILD_WRKSRC}/binaries && ./run_tests.sh)
.endif

post-install:
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}/${EXAMPLESDIR}

.include <bsd.port.mk>
