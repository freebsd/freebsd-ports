# Created by: faulkner@mpd.tandem.com
# $FreeBSD$

PORTNAME=	rsynth
PORTVERSION=	2.0
PORTREVISION=	4
CATEGORIES=	audio accessibility
MASTER_SITES=	ftp://svr-ftp.eng.cam.ac.uk/pub/comp.speech/synthesis/ \
		ftp://ftp.enst.fr/pub/unix/multimedia/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Speech synthesizer

LIB_DEPENDS=	libgdbm.so:databases/gdbm \
		libaudio.so:audio/nas

USES=		autoreconf
GNU_CONFIGURE=	yes

pre-configure:
	@${CP} ${FILESDIR}/freebsdplay.c ${WRKSRC}/config/freebsdplay.c

post-configure:
	@${REINPLACE_CMD} -E 's,(BIN|LIB)_DIR\),DESTDIR\)$$\(&,g' \
		${WRKSRC}/Makefile

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/dict

.include <bsd.port.mk>
