# Created by: Aragon Gouveia <aragon@phat.za.net>
# $FreeBSD$

PORTNAME=	alsa-utils
PORTVERSION=	1.0.27.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ALSA/utils \
		GENTOO/distfiles

MAINTAINER=	aragon@phat.za.net
COMMENT=	ALSA compatibility utils

LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins

USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-udev-rules-dir="\$${prefix}/lib/udev"
CFLAGS+=	-I${LOCALBASE}/include

OPTIONS_SUB=	yes
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
	${REINPLACE_CMD} -e '/LIBS/s/-ldl//g; /LIBRT/s/-lrt//g;' \
		${WRKSRC}/configure
	${FIND} -E ${WRKSRC} -type f -regex \
		'.*\.([[:digit:]]|spec\.in|csv|xml)' -exec \
		${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		-e 's|/etc/asound\.conf|${LOCALBASE}&|g' {} +

.include <bsd.port.mk>
