# Created by: gahr
# $FreeBSD$

PORTNAME=	dcd
PORTVERSION=	0.99.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}player/${PORTNAME}player/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple, programmable, intelligent CD player

LICENSE=	GPLv2

LIB_DEPENDS=	libcdaudio.so:audio/libcdaudio

USES=		gmake

PLIST_FILES=	bin/dcd \
		man/man1/dcd.1.gz

post-patch:
	# Handle namespace collision with libcdaudio
	${REINPLACE_CMD} -e 's|cd_stop|dcd_stop|g; s|cd_eject|dcd_eject|g; \
	    s|cd_pause|dcd_pause|g; s|cd_play_track|dcd_play_track|g' \
	    ${WRKSRC}/dcd.c ${WRKSRC}/infinite.c
	# Linux? Bugger off!
	${REINPLACE_CMD} -e 's|linux/||' ${WRKSRC}/process.c
	${REINPLACE_CMD} -e 's|<endian|<sys/endian|; s|__BYTE_ORDER|_BYTE_ORDER|' \
	    ${WRKSRC}/endian.h

.include <bsd.port.mk>
