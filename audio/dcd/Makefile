# New ports collection Makefile for:	dcd
# Date created:				20 June 2008
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	dcd
PORTVERSION=	0.99.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}player/${PORTNAME}player/${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A simple, programmable, intelligent CD player

LIB_DEPENDS=	cdaudio:${PORTSDIR}/audio/libcdaudio

USE_GMAKE=	yes

MAN1=	dcd.1
PLIST_FILES=	bin/dcd

LATEST_LINK=	audio_dcd

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
