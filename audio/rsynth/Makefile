# New ports collection makefile for:	rsynth
# Date created:		03 Jan 1995
# Whom:			faulkner@mpd.tandem.com
#
# $FreeBSD$
#

PORTNAME=	rsynth
PORTVERSION=	2.0
CATEGORIES=	audio
MASTER_SITES=	ftp://svr-ftp.eng.cam.ac.uk/pub/comp.speech/synthesis/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Speech synthesizer

BUILD_DEPENDS=	${LOCALBASE}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm \
		${X11BASE}/include/audio/audiolib.h:${PORTSDIR}/audio/nas

GNU_CONFIGURE=	yes

pre-configure:
	@${CP} ${FILESDIR}/freebsdplay.c ${WRKSRC}/config/freebsdplay.c
	@${CP} ${FILESDIR}/config.guess ${WRKSRC}/config.guess
	@${CP} ${FILESDIR}/config.sub ${WRKSRC}/config.sub
	@${CP} ${FILESDIR}/configure ${WRKSRC}/configure

.include <bsd.port.mk>
