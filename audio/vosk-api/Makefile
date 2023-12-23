PORTNAME=	vosk-api
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.45-20231214
CATEGORIES=	audio # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Vosk: Offline open source speech recognition toolkit (API)
WWW=		https://alphacephei.com/vosk/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfst.so:math/openfst-vosk \
		libkaldi-base.so:audio/kaldi-vosk

USES=		cmake compiler:c++17-lang localbase:ldflags
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	alphacep
GH_TAGNAME=	aba8497

CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_FILES=	include/vosk_api.h \
		lib/libvosk.so

.include <bsd.port.mk>
