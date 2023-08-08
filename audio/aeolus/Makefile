PORTNAME=	aeolus
DISTVERSION=	0.10.4
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://kokkinizita.linuxaudio.org/linuxaudio/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Synthesised pipe organ emulator
WWW=		https://kokkinizita.linuxaudio.org/linuxaudio/aeolus/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libclthreads.so:devel/clthreads \
		libclxclient.so:devel/clxclient \
		libjack.so:audio/jack \
		libzita-alsa-pcmi.so:audio/zita-alsa-pcmi

USES=		gmake localbase:ldflags pkgconfig readline tar:bz2 xorg
USE_XORG=	x11 xft

WRKSRC_SUBDIR=	source

PLIST_FILES=	bin/aeolus \
		lib/aeolus_txt.so \
		lib/aeolus_x11.so

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/aeolus \
		${STAGEDIR}${PREFIX}/lib/aeolus_txt.so \
		${STAGEDIR}${PREFIX}/lib/aeolus_x11.so

.include <bsd.port.mk>
