PORTNAME=	catch2 # 2.x series is under devel/catch, the project is called catch2
DISTVERSIONPREFIX=	v
DISTVERSION=	3.7.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Test framework for C++ (3.x series)
WWW=		https://github.com/catchorg/Catch2

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:testing compiler:c++14-lang pathfix python:build,test
USE_GITHUB=	yes
GH_ACCOUNT=	catchorg
GH_PROJECT=	Catch2

CMAKE_ARGS=	-DCMAKE_INSTALL_DOCDIR=${DOCSDIR} \
		-DPython3_EXECUTABLE=${PYTHON_CMD}
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	CATCH_DEVELOPMENT_BUILD BUILD_TESTING CATCH_BUILD_TESTING # 1 test fails, see https://github.com/catchorg/Catch2/issues/2606

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

CONFLICTS=	catch

.include <bsd.port.mk>
