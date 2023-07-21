PORTNAME=	outcome
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.4-20230715
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++14 library for reporting and handling function failures
WWW=		https://ned14.github.io/outcome/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/Licence.txt

BUILD_DEPENDS=	${LOCALBASE}/include/quickcpplib/config.hpp:devel/quickcpplib
RUN_DEPENDS=	${LOCALBASE}/include/quickcpplib/config.hpp:devel/quickcpplib

USES=		cmake:testing compiler:c++14-lang

USE_GITHUB=	yes
GH_ACCOUNT=	ned14
GH_TAGNAME=	0bedf67
GH_TUPLE=	ned14:status-code:6827965:status_code/include/outcome/experimental/status-code

CMAKE_TESTING_ON=	OUTCOME_ENABLE_DEPENDENCY_SMOKE_TEST
CMAKE_ARGS=	-Dquickcpplib_DIR=${LOCALBASE}/lib/cmake/quickcpplib

NO_BUILD=	yes
NO_ARCH=	yes

PORTSCOUT=	limit:^.*[0-9]\.[0-9].*

post-patch: # remove the test folter until the problems are fixed by the upstream
	# tests have problems:
	# - they are unconditionally built, see https://github.com/ned14/outcome/issues/285
	# - they fail to compile, see https://github.com/ned14/outcome/issues/286
	@${RM} -r ${WRKSRC}/test

.include <bsd.port.mk>
