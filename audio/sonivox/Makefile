PORTNAME=	sonivox
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.0
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

CONFIGURE_ENV=	${MAKE_ENV} TEMP=${BUILD_WRKSRC}

# tests as of 4.0.0: 75% tests passed, 3 tests failed out of 12, see https://github.com/EmbeddedSynth/sonivox/issues/5

.include <bsd.port.mk>
