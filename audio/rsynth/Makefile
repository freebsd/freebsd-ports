# Created by: faulkner@mpd.tandem.com
# $FreeBSD$

PORTNAME=	rsynth
PORTVERSION=	2.0
PORTREVISION=	7
CATEGORIES=	audio accessibility
MASTER_SITES=	ftp://svr-ftp.eng.cam.ac.uk/pub/comp.speech/synthesis/ \
		ftp://ftp.enst.fr/pub/unix/multimedia/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Speech synthesizer

LICENSE=	PD

OPTIONS_DEFINE=		DB NAS SNDIO
OPTIONS_SUB=		yes

DB_DESC=		Build dictionary database tools
DB_LIB_DEPENDS=		libgdbm.so:databases/gdbm
DB_CONFIGURE_ENV_OFF=	ac_cv_lib_gdbm_gdbm_open=no
NAS_LIB_DEPENDS=	libaudio.so:audio/nas
NAS_CONFIGURE_ENV_OFF=	ac_cv_header_audio_audiolib_h=no
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_MAKE_ENV=		SAY_LIBS=-lsndio

USES=		autoreconf
GNU_CONFIGURE=	yes

pre-configure-SNDIO-on:
	@${CP} ${FILESDIR}/sndioplay.c ${WRKSRC}/config/freebsdplay.c

pre-configure-SNDIO-off:
	@${CP} ${FILESDIR}/ossplay.c ${WRKSRC}/config/freebsdplay.c

post-configure:
	@${REINPLACE_CMD} -E 's,(BIN|LIB)_DIR\),DESTDIR\)$$\(&,g' \
		${WRKSRC}/Makefile

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/dict

.include <bsd.port.mk>
