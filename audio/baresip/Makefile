# $FreeBSD$

PORTNAME=	baresip
PORTVERSION=	0.5.8
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://www.creytiv.com/pub/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Small SIP client

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/docs/COPYING

BUILD_DEPENDS=	re>=0.5.8:audio/re \
		rem>=0.5.3:audio/rem
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake pkgconfig ssl
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/ilbc
MAKE_ARGS=	MOD_AUTODETECT=""
PLIST_FILES=	bin/baresip
PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

#OPTIONS_NOT_YET_WORKING=	ALSA BV32 G722_1 PLC ISAC OPENGLES
OPTIONS_DEFINE=	CONS DOCS EXAMPLES FFMPEG G711 G722 G726 GSM GSTREAMER ILBC \
	L16 OPUS OSS PORTAUDIO PULSEAUDIO SDL SNDFILE SPEEX STDIO UUID V4L V4L2 X11 \
	DTLS_SRTP AUBRIDGE VIDBRIDGE HTTPD DSHOW DIRECTFB ACCOUNT \
	NATPMP SDL MIW SNAPSHOT SELFVIEW VUMETER AULOOP CONTACT \
	MENU PRESENCE SYSLOG VIDLOOP
OPTIONS_DEFAULT=CONS G711 G722 G726 L16 OSS STDIO

AULOOP_DESC=	Audio-loop test module
BV32_DESC=	BroadVoice32 Wideband Audio codec
CONTACT_DESC=	Contacts module
CONS_DESC=	Console input driver
DTLS_SRTP_DESC=	DTLS Secure RTP module [broken]
G711_DESC=	G.711 audio codec
G722_DESC=	G.722 audio codec
G722_1_DESC=	G.722.1 audio codec
G726_DESC=	G.726 audio codec
ILBC_DESC=	iLBC audio codec
L16_DESC=	L16 audio codec
MENU_DESC=	Interactive menu
OPENGLES_DESC=	OpenGL ES video output
PLC_DESC=	Packet Loss Concealment
PRESENCE_DESC=	Presence module
STDIO_DESC=	stdio input driver
SYSLOG_DESC=	Syslog module
UUID_DESC=	UUID module
V4L_DESC=	Video4Linux module [broken]
V4L2_DESC=	Video4Linux2 module [broken]
VIDLOOP_DESC=	Video-loop test module
X11_DESC=	X11 module [broken]

.for o in ${OPTIONS_DEFINE}
.  ifndef $o_DESC
$o_DESC=	${o:C,^(.).*,\1,}${o:C,^.,,:tl} module
.  endif
.endfor

.include <bsd.port.options.mk>

.include "${.CURDIR}/Makefile.depends"

# Port calls it GST, standard OPTION is GSTREAMER
.if ${PORT_OPTIONS:MGSTREAMER}
PORT_OPTIONS+=	GST
.endif

# Port calls it PULSE, standard OPTION is PULSEAUDIO
.if ${PORT_OPTIONS:MPULSEAUDIO}
PORT_OPTIONS+=	PULSE
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl sound
.endif

# SPEEX forces install of speex, therefore may as well enable all methods
.if ${PORT_OPTIONS:MSPEEX}
. for s in SPEEX_AEC SPEEX_PP SPEEX_RESAMP
MAKE_ARGS+=	USE_$s=yes
. endfor
MAKE_ARGS+=	HAVE_SPEEXDSP=yes
.endif

.for o in V4L DTLS_SRTP V4L2 X11
.  if ${PORT_OPTIONS:M$o}
BROKEN=	OPTIONS marked as BROKEN have not been updated to the new Baresip API
.  endif
.endfor

.if ${PORT_OPTIONS:MX11}
USES+=		xorg
USE_XORG=	x11
.endif

.for o in ${PORT_OPTIONS}
MAKE_ARGS+=	USE_$o=yes
BUILD_DEPENDS+=	${$o_DEPEND}
RUN_DEPENDS+=	${$o_DEPEND}
.endfor

# GNU Make does not do make -V, which makes life difficult
post-patch:
	${ECHO_CMD} >> ${WRKSRC}/Makefile
	${ECHO_CMD} ".PHONY: showmodules" >> ${WRKSRC}/Makefile
	${ECHO_CMD} "showmodules:" >> ${WRKSRC}/Makefile
	${ECHO_CMD} '	@${ECHO_CMD} $$(MODULES)' >> ${WRKSRC}/Makefile
	${REINPLACE_CMD} 's,-lportaudio[0-9]*,-L${LOCALBASE}/lib -lportaudio,' \
		${WRKSRC}/modules/portaudio/module.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/share/* ${STAGEDIR}${DATADIR}

	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/modules
	for m in $$(${SETENV} ${MAKE_ENV} ${MAKE_CMD} -sC ${WRKSRC} ${MAKE_ARGS} showmodules); \
	do ${INSTALL_LIB} ${WRKSRC}/$$m.so \
		${STAGEDIR}${PREFIX}/lib/baresip/modules; \
	   ${ECHO_CMD} lib/${PORTNAME}/modules/$$m.so >> ${TMPPLIST}; \
	done
	${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${MV} ${STAGEDIR}${DOCSDIR}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	${RMDIR} ${STAGEDIR}${DOCSDIR}/examples

.include <bsd.port.mk>
