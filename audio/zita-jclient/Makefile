PORTNAME=	zita-jclient
DISTVERSION=	0.5.2
CATEGORIES=	audio
MASTER_SITES=	https://kokkinizita.linuxaudio.org/linuxaudio/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to create a Jack client with a few lines of C++
WWW=		https://kokkinizita.linuxaudio.org/linuxaudio/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libjack.so:audio/jack

USES=		gmake localbase:ldflags pkgconfig tar:bz2
USE_LDCONFIG=	yes

ALL_TARGET=	libzita-jclient.so.${DISTVERSION}

WRKSRC_SUBDIR=	source

PLIST_FILES=	include/zita-jclient.h \
		lib/libzita-jclient.so \
		lib/libzita-jclient.so.${DISTVERSION}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libzita-jclient.so.${DISTVERSION}

.include <bsd.port.mk>
