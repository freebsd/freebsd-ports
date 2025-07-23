PORTNAME=	freealut
DISTVERSION=	1.1.0.20240801
PORTEPOCH=	1
CATEGORIES=	audio

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	The OpenAL Utility Toolkit
WWW=		https://github.com/vancegroup/freealut

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	No longer actively developed, consider migrating to another library

USES=		cmake localbase:ldflags openal
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	vancegroup
GH_TAGNAME=	8abb420

LDFLAGS_i386=	-Wl,-znotext

CMAKE_OFF=	BUILD_EXAMPLES \
		BUILD_OPTIMIZATION \
		BUILD_TESTS

.include <bsd.port.mk>
