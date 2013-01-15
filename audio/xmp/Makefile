# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	xmp
PORTVERSION=	3.5.0
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A player for many different Amiga and PC module formats

LICENSE=	GPLv2

USE_GMAKE=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc --disable-arts \
		--disable-audacious-plugin

MAN1=		xmp.1

OPTIONS_DEFINE=	ALSA BMP ESOUND NAS PULSEAUDIO UNZIP XMMS DOCS

BMP_DESC=	Beep media player plugin
XMMS_DESC=	XMMS plugin

OPTIONS_DEFAULT=UNZIP

MAKE_JOBS_SAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.options.mk>

PORTDOCS=	*

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins
CONFIGURE_ARGS+=	--enable-alsa
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if ${PORT_OPTIONS:MBMP}
LIB_DEPENDS+=	beep:${PORTSDIR}/multimedia/beep-media-player
CONFIGURE_ARGS+=	--enable-bmp-plugin
PLIST_SUB+=	BMP=""
.else
CONFIGURE_ARGS+=	--disable-bmp-plugin
PLIST_SUB+=	BMP="@comment "
.endif

.if ${PORT_OPTIONS:MESOUND}
USE_GNOME+=	esound
CONFIGURE_ARGS+=	--enable-esd
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

.if ${PORT_OPTIONS:MNAS}
LIB_DEPENDS+=	audio:${PORTSDIR}/audio/nas
CONFIGURE_ARGS+=	--enable-nas
.else
CONFIGURE_ARGS+=	--disable-nas
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse-simple:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=	--enable-pulseaudio
.else
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif

.if ${PORT_OPTIONS:MUNZIP}
RUN_DEPENDS+=	${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip
.else
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-src-misc-load.c
.endif

.if ${PORT_OPTIONS:MXMMS}
LIB_DEPENDS+=	xmms:${PORTSDIR}/multimedia/xmms
CONFIGURE_ARGS+=	--enable-xmms-plugin
PLIST_SUB+=	XMMS=""
.else
CONFIGURE_ARGS+=	--disable-xmms-plugin
PLIST_SUB+=	XMMS="@comment "
.endif

post-patch:	.SILENT
.for f in docs/xmp.1 etc/xmp.conf etc/modules.conf
	${REINPLACE_CMD} -e "s|/etc/xmp|${ETCDIR}|g" ${WRKSRC}/${f}
.endfor
	${REINPLACE_CMD} -e \
		'/$$(INSTALL_DATA)/s|\([[:alnum:]]*\.conf\).*$$|&\1.sample|' \
		${WRKSRC}/etc/Makefile
	@${REINPLACE_CMD} -e \
		's|-Wno-unknown-warning-option -Wno-unused-but-set-variable||' \
		${WRKSRC}/configure

post-install:	.SILENT
	if  [ ! -f ${ETCDIR}/${PORTNAME}.conf ]; then \
		${INSTALL_DATA} ${ETCDIR}/${PORTNAME}.conf.sample \
			${ETCDIR}/${PORTNAME}.conf; \
	fi
	if [ ! -f ${ETCDIR}/modules.conf ]; then \
		${INSTALL_DATA} ${ETCDIR}/modules.conf.sample \
			${ETCDIR}/modules.conf; \
	fi

.if ${PORT_OPTIONS:MDOCS}
	${ECHO_MSG} Installing documentation in ${DOCSDIR}
	( cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \* \
		${DOCSDIR} '! ( -name Makefile -or -name xmp.1 \
		-or -name *.bak -or -name *.orig )' )
.endif

.include <bsd.port.mk>
