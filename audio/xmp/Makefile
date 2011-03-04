# New ports collection makefile for: 	xmp
# Date created:				18 September 1999
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	xmp
PORTVERSION=	3.3.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A player for many different Amiga and PC module formats

USE_GMAKE=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc

MAN1=		xmp.1

OPTIONS=	ALSA    "ALSA output driver" off \
		ARTS	"aRts output driver" off \
		AUDACIOUS	"Audacious plugin" off \
		BMP	"BeepMP plugin" off \
		ESOUND	"EsounD output driver" off \
		NAS	"Network Audio System ouptut driver" off \
		PULSEAUDIO	"PulseAudio output driver" off \
		UNZIP	"Use unzip(1) not bsdtar(1) to read .zip files" on \
		XMMS	"XMMS plugin" off

MAKE_JOBS_SAFE=	yes

LICENSE=	GPLv2

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.if defined(WITH_ALSA)
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins
CONFIGURE_ARGS+=	--enable-alsa
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
CONFIGURE_ARGS+=	--enable-arts
.else
CONFIGURE_ARGS+=	--disable-arts
.endif

.if defined(WITH_AUDACIOUS)
LIB_DEPENDS+=	audclient.2:${PORTSDIR}/multimedia/audacious
CONFIGURE_ARGS+=	--enable-audacious-plugin
PLIST_SUB+=	AUDACIOUS=""
.else
CONFIGURE_ARGS+=	--disable-audacious-plugin
PLIST_SUB+=	AUDACIOUS="@comment "
.endif

.if defined(WITH_BMP)
LIB_DEPENDS+=	beep.2:${PORTSDIR}/multimedia/beep-media-player
CONFIGURE_ARGS+=	--enable-bmp-plugin
PLIST_SUB+=	BMP=""
.else
CONFIGURE_ARGS+=	--disable-bmp-plugin
PLIST_SUB+=	BMP="@comment "
.endif

.if defined(WITH_ESOUND)
USE_GNOME+=	esound
CONFIGURE_ARGS+=	--enable-esd
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

.if defined(WITH_NAS)
LIB_DEPENDS+=	audio.2:${PORTSDIR}/audio/nas
CONFIGURE_ARGS+=	--enable-nas
.else
CONFIGURE_ARGS+=	--disable-nas
.endif

.if defined(WITH_PULSEAUDIO)
LIB_DEPENDS+=	pulse-simple.0:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=	--enable-pulseaudio
.else
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif

.if defined(WITH_UNZIP)
RUN_DEPENDS+=	${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip
.else
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-src-misc-load.c
.endif

.if defined(WITH_XMMS)
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
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

post-install:	.SILENT
	if  [ ! -f ${ETCDIR}/${PORTNAME}.conf ]; then \
		${INSTALL_DATA} ${ETCDIR}/${PORTNAME}.conf.sample \
			${ETCDIR}/${PORTNAME}.conf; \
	fi
	if [ ! -f ${ETCDIR}/modules.conf ]; then \
		${INSTALL_DATA} ${ETCDIR}/modules.conf.sample \
			${ETCDIR}/modules.conf; \
	fi

.if !defined(NOPORTDOCS)
	${ECHO_MSG} Installing documentation in ${DOCSDIR}
	( cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \* \
		${DOCSDIR} '! ( -name Makefile -or -name xmp.1 \
		-or -name *.bak -or -name *.orig )' )
.endif

.include <bsd.port.post.mk>
