# New ports collection makefile for:	rsynth
# Version required:	2.0
# Date created:		03 Jan 1995
# Whom:			faulkner@mpd.tandem.com
#
# Makefile,v 1.0 1995/01/03 10:47:27 paf Exp
#

DISTNAME=	rsynth-2.0
CATEGORIES=	audio
MASTER_SITES=	ftp://svr-ftp.eng.cam.ac.uk/pub/comp.speech/sources/

EXEC_DEPENDS=	auvoxware:${PORTSDIR}/audio/nas

GNU_CONFIGURE=	YES

pre-configure:
	@cp ${FILESDIR}/freebsdplay.c ${WRKSRC}/config/freebsdplay.c
	@cp ${FILESDIR}/config.guess ${WRKSRC}/config.guess
	@cp ${FILESDIR}/config.sub ${WRKSRC}/config.sub
	@cp ${FILESDIR}/configure ${WRKSRC}/configure

.include <bsd.port.mk>
