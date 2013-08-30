# Created by: Aragon Gouveia <aragon@phat.za.net>
# $FreeBSD$

PORTNAME=	alsa-utils
PORTVERSION=	1.0.26
CATEGORIES=	audio
MASTER_SITES=	ALSA/utils \
		GENTOO/distfiles

MAINTAINER=	aragon@phat.za.net
COMMENT=	ALSA compatibility utils

LIB_DEPENDS=	asound:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins

USE_BZIP2=	yes
USES=		gmake
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include

MAN1_EN=	aconnect.1 alsactl.1 alsaloop.1 alsamixer.1 amidi.1 amixer.1 aplay.1 aplaymidi.1 \
		arecordmidi.1 aseqdump.1 aseqnet.1 iecset.1 speaker-test.1
MAN8=		alsaconf.8
MLINKS=		aplay.1 arecord.1
_MANPAGES+=	${PREFIX}/man/fr/man8/${MAN8}

OPTIONS_DEFINE=	XMLTO NLS
OPTIONS_DEFAULT=XMLTO
XMLTO_DESC=	Generate alsactl_init(7) man page using xmlto(1)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXMLTO}
BUILD_DEPENDS+=	xmlto:${PORTSDIR}/textproc/xmlto
MAN7_EN+=	alsactl_init.7
.else
CONFIGURE_ARGS+=--disable-xmlto
.endif

.if empty(PORT_OPTIONS:MNLS)
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
USES+=		gettext
PLIST_SUB+=	NLS=""
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} '/LIBS/s/-ldl//g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e '/install-data-am:/,/^$$/ \
		s/install-dist_udevrulesDATA//' \
		${WRKSRC}/alsactl/Makefile.in
	${FIND} -E ${WRKSRC} -type f -regex \
		'.*\.([[:digit:]]|spec\.in|csv|xml)' -exec \
		${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		-e 's|/etc/asound\.conf|${LOCALBASE}&|g' {} +

.include <bsd.port.mk>
