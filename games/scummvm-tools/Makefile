# New ports collection makefile for:	scummvm-tools
# Date created:				28 May 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scummvm-tools
PORTVERSION=	0.13.0
PORTREVISION=	2
CATEGORIES=	games emulators
MASTER_SITES=	SF/scummvm/${PORTNAME}/${PORTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Tools for use with the SCUMMVM game emulator

RUN_DEPENDS=	scummvm:${PORTSDIR}/games/scummvm
BUILD_DEPENDS=	lame:${PORTSDIR}/audio/lame \
		flac:${PORTSDIR}/audio/flac \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		oggdec:${PORTSDIR}/audio/vorbis-tools \

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		vorbis.4:${PORTSDIR}/audio/libvorbis

USE_BZIP2=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/scummvm-tools-${PORTVERSION}

MAKE_JOBS_SAFE=	yes

MAKE_ENV=	"LDFLAGS= -L${LOCALBASE}/lib"
CXXFLAGS=	-I${LOCALBASE}/include

OPTIONS=	WX "Build wxWidgets GUI" On

.include <bsd.port.pre.mk>

.if defined(WITH_WX)
USE_WX=		2.4+
WX_CONFIG=	${LOCALBASE}/bin/wxgtk2-2.8-config
WX_COMP=	wx:lib:build
GUI_BIN=	tools_gui
PLIST_SUB=	WX=""
.else
PLIST_SUB=	WX="@comment "
.endif

post-patch:
.if defined(WITH_WX)
	@${REINPLACE_CMD} -e 's,wx-config,${WX_CONFIG},' ${WRKSRC}/Makefile
.else
	@${REINPLACE_CMD} -e '/tools_gui$$(EXEEXT)$$/d' ${WRKSRC}/Makefile
.endif

do-install:
.for i in compress_agos compress_kyra compress_queen compress_saga \
		compress_scumm_bun compress_scumm_san compress_scumm_sou \
		compress_sword1 compress_sword2 compress_touche compress_tucker \
		decine dekyra descumm desword2 degob encode_dxa extract_agos \
		extract_cine extract_kyra extract_loom_tg16 extract_mm_apple \
		extract_mm_c64 extract_mm_nes extract_parallaction \
		extract_scumm_mac extract_t7g_mac extract_zak_c64 \
		extract_gob_stk ${GUI_BIN}
	@${INSTALL_PROGRAM} ${WRKSRC}/$i ${PREFIX}/bin
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
