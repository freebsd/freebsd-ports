# $FreeBSD$

PORTNAME=	baresip
PORTVERSION=	0.4.2
CATEGORIES=	audio
MASTER_SITES=	http://www.creytiv.com/pub/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Small SIP client

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/docs/COPYING

BUILD_DEPENDS=	re>=${PORTVERSION}:${PORTSDIR}/audio/re \
		rem>=${PORTVERSION}:${PORTSDIR}/audio/rem
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/ilbc
MAKE_ARGS=	MOD_AUTODETECT=""
PLIST_FILES=	bin/baresip
PORTDATA=	*
PORTDOCS=	*

#OPTIONS_NOT_YET_WORKING=	ALSA BV32 G722_1 PLC
OPTIONS_DEFINE=	CELT CONS DOCS FFMPEG G711 G722 GSM GSTREAMER ILBC L16 OPUS \
		OSS PORTAUDIO SDL SNDFILE SPEEX SRTP STDIO UUID V4L V4L2 X11
OPTIONS_DEFAULT=CONS G711 G722 L16

BV32_DESC=	BroadVoice32 Wideband Audio codec
CONS_DESC=	Console input driver
G711_DESC=	G.711 audio codec
G722_DESC=	G.722 audio codec
G722_1_DESC=	G.722.1 audio codec
ILBC_DESC=	iLBC audio codec
L16_DESC=	L16 audio codec
OPUS_DESC=	Opus audio codec
PLC_DESC=	Packet Loss Concealment
SRTP_DESC=	Secure RTP module
STDIO_DESC=	stdio input driver
UUID_DESC=	UUID module
V4L_DESC=	Video4Linux module
V4L2_DESC=	Video4Linux2 module

.include <bsd.port.options.mk>

.include "${.CURDIR}/Makefile.depends"

# Port calls it GST, standard OPTION is GSTREAMER
.if ${PORT_OPTIONS:MGSTREAMER}
PORT_OPTIONS+=	GST
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

.if ${PORT_OPTIONS:MX11}
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
	${REINPLACE_CMD} 's,-lcelt[0-9]*,$$(pkg-config --libs celt),' \
		${WRKSRC}/modules/celt/module.mk
	${REINPLACE_CMD} 's,-lportaudio[0-9]*,-L${LOCALBASE}/lib/portaudio2 -lportaudio,' \
		${WRKSRC}/modules/portaudio/module.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/share/* ${DATADIR}

# Install modules and add to plist
post-install:
	${MKDIR} ${PREFIX}/lib/${PORTNAME}/modules
	for m in $$(${GMAKE} -sC ${WRKSRC} ${MAKE_ARGS} showmodules); \
	do ${INSTALL_LIB} ${WRKSRC}/$$m.so ${PREFIX}/lib/baresip/modules; \
	   ${ECHO_CMD} lib/${PORTNAME}/modules/$$m.so >> ${TMPPLIST}; \
	done
	${ECHO_CMD} "@dirrm lib/baresip/modules" >> ${TMPPLIST}
	${ECHO_CMD} "@dirrm lib/baresip" >> ${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
