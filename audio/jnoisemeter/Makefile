PORTNAME=	jnoisemeter
DISTVERSION=	0.4.1
CATEGORIES=	audio
MASTER_SITES=	https://kokkinizita.linuxaudio.org/linuxaudio/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Jack app for measurement of audio signals, in particular noise signals
WWW=		https://kokkinizita.linuxaudio.org/linuxaudio/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libclthreads.so:devel/clthreads \
		libclxclient.so:devel/clxclient \
		libjack.so:audio/jack

USES=		gmake localbase:ldflags pkgconfig tar:bz2 xorg
USE_XORG=	x11 xft
USE_LDCONFIG=	yes

WRKSRC_SUBDIR=	source

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
