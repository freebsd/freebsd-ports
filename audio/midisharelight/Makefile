PORTNAME=	midisharelight
DISTVERSION=	g20200204
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Light version of the MidiShare library

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	grame-cncm
GH_TAGNAME=	2f4fc2a

CMAKE_SOURCE_PATH=	${WRKSRC}/cmake

CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_FILES=	include/MidiShareLight.h \
		include/midifile.h \
		lib/libmidisharelight.so

.include <bsd.port.mk>
