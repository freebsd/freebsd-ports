# New ports collection makefile for:	rsynth
# Version required:	2.0
# Date created:		03 Jan 1995
# Whom:			faulkner@mpd.tandem.com
#
# $Id: Makefile,v 1.7 1996/11/15 06:11:41 asami Exp $
#

DISTNAME=	rsynth-2.0
CATEGORIES=	audio
MASTER_SITES=	ftp://svr-ftp.eng.cam.ac.uk/pub/comp.speech/synthesis/

MAINTAINER=	faulkner@mpd.tandem.com

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm
EXEC_DEPENDS=	auvoxware:${PORTSDIR}/audio/nas

GNU_CONFIGURE=	YES

pre-configure:
	@${CP} ${FILESDIR}/freebsdplay.c ${WRKSRC}/config/freebsdplay.c
	@${CP} ${FILESDIR}/config.guess ${WRKSRC}/config.guess
	@${CP} ${FILESDIR}/config.sub ${WRKSRC}/config.sub
	@${CP} ${FILESDIR}/configure ${WRKSRC}/configure

.include <bsd.port.mk>
