PORTNAME=	snitch
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.2
CATEGORIES=	devel
PKGNAMESUFFIX=	-testing

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight C++20 testing framework
WWW=		https://github.com/cschreib/snitch

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	doctest>0:devel/doctest

USES=		cmake:testing compiler:c++20-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	cschreib

FLAVORS=	default headers_only
FLAVOR?=	${FLAVORS:[1]}
headers_only_PLIST=	${MASTERDIR}/pkg-plist-headers-only

.if ${FLAVOR} == default
CMAKE_ON=	BUILD_SHARED_LIBS
.endif

.if ${FLAVOR} == headers_only
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-headers-only
CMAKE_ON=	SNITCH_HEADER_ONLY
NO_ARCH=	yes
CONFLICTS_INSTALL=	snitch-testing # see https://github.com/cschreib/snitch/issues/125
.endif

CMAKE_ON+=		SNITCH_USE_SYSTEM_DOCTEST
CMAKE_TESTING_ON=	SNITCH_DO_TEST SNITCH_ENABLE
CMAKE_TESTING_TARGET=	snitch_runtime_tests_run \
			snitch_runtime_tests_self_run \
			snitch_approval_tests_run # unclear how to run all tests

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/doc/snitch/LICENSE
	@${RMDIR} \
		${STAGEDIR}${PREFIX}/doc/snitch \
		${STAGEDIR}${PREFIX}/doc

# many tests fail, see https://github.com/snitch-org/snitch/issues/206

.include <bsd.port.mk>
