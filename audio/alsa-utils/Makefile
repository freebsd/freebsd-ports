# New ports collection makefile for:   alsa-utils
# Date created:                June 29, 2009
# Whom:                        Aragon Gouveia <aragon@phat.za.net>
#
# $FreeBSD$
#

PORTNAME=	alsa-utils
PORTVERSION=	1.0.23
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.silug.org/pub/alsa/utils/ \
		ftp://gd.tuwien.ac.at/opsys/linux/alsa/utils/ \
		http://dl.ambiweb.de/mirrors/ftp.alsa-project.org/utils/ \
		ftp://ftp.alsa-project.org/pub/utils/

MAINTAINER=	aragon@phat.za.net
COMMENT=	ALSA compatibility utils

LIB_DEPENDS=	asound.2:${PORTSDIR}/audio/alsa-lib
BUILD_DEPENDS=	xmlto:${PORTSDIR}/textproc/xmlto
RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--disable-nls

MANLANG=	"" fr
MAN1_EN=	aconnect.1 alsactl.1 alsamixer.1 amidi.1 amixer.1 aplay.1 aplaymidi.1 \
		arecordmidi.1 aseqdump.1 aseqnet.1 iecset.1 speaker-test.1
MAN7_EN=	alsactl_init.7
MAN8_EN=	alsaconf.8
MAN8_FR=	alsaconf.8
MLINKS_EN=	aplay.1 arecord.1

post-patch:	.SILENT
	${REINPLACE_CMD} '/LIBS/s/-ldl//g' ${WRKSRC}/configure

.include <bsd.port.mk>
