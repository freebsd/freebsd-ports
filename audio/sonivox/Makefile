PORTNAME=	sonivox
DISTVERSIONPREFIX=	v
DISTVERSION=	3.6.16
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fork of the AOSP 'platform_external_sonivox' to use out of Android
WWW=		https://github.com/pedrolcl/sonivox

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	pedrolcl

CXXFLAGS+=	-DO_LARGEFILE=0 # workaround for linuxism in tests

CMAKE_OFF=	BUILD_TESTING

CONFIGURE_ENV=	${MAKE_ENV} TEMP=${BUILD_WRKSRC}

# tests as of 3.6.16: 45% tests passed, 18 tests failed out of 33, see https://github.com/pedrolcl/sonivox/issues/102

.include <bsd.port.mk>
