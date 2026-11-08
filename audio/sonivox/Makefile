PORTNAME=	sonivox
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.2
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Evolution of the AOSP 'platform_external_sonivox'
WWW=		https://github.com/EmbeddedSynth/sonivox

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	EmbeddedSynth

CXXFLAGS+=	-DO_LARGEFILE=0 # workaround for linuxism in tests

CMAKE_OFF=	BUILD_TESTING
CMAKE_ON=	SOUNDFONT_TEST # option is only used for testing

CONFIGURE_ENV=	${MAKE_ENV} TEMP=${BUILD_WRKSRC}
TEST_ENV=	${MAKE_ENV} TEMP=${BUILD_WRKSRC}

# tests as of 4.0.2: 100% tests passed, 0 tests failed out of 12

.include <bsd.port.mk>
