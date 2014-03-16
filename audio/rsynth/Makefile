# Created by: faulkner@mpd.tandem.com
# $FreeBSD$

PORTNAME=	rsynth
PORTVERSION=	2.0
PORTREVISION=	4
CATEGORIES=	audio accessibility
MASTER_SITES=	ftp://svr-ftp.eng.cam.ac.uk/pub/comp.speech/synthesis/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Speech synthesizer

LIB_DEPENDS=	libgdbm.so:${PORTSDIR}/databases/gdbm	\
		libaudio.so:${PORTSDIR}/audio/nas

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf

pre-configure:
	@${CP} ${FILESDIR}/freebsdplay.c ${WRKSRC}/config/freebsdplay.c

post-configure:
	@${REINPLACE_CMD} -E 's,(BIN|LIB)_DIR\),DESTDIR\)$$\(&,g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
