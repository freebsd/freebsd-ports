# New ports collection makefile for:	scummvm-tools
# Date created:				28 May 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scummvm-tools
PORTVERSION=	0.10.0
CATEGORIES=	games emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	scummvm

MAINTAINER=	lars.engels@0x20.net
COMMENT=	Tools for use with the SCUMMVM game emulator

RUN_DEPENDS=	scummvm:${PORTSDIR}/games/scummvm
BUILD_DEPENDS=	lame:${PORTSDIR}/audio/lame \
		flac:${PORTSDIR}/audio/flac \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		oggdec:${PORTSDIR}/audio/vorbis-tools
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/scummvm-tools-${PORTVERSION}

do-install:
.for i in compress_agos compress_kyra compress_queen compress_saga compress_scumm_bun \
		compress_scumm_san compress_scumm_sou compress_sword1 compress_sword2 \
		compress_touche dekyra descumm desword2 encode_dxa extract_agos \
		extract_kyra extract_loom_tg16 extract_mm_apple extract_mm_c64 \
		extract_mm_nes extract_scumm_mac extract_zak_c64
	@${INSTALL_PROGRAM} ${WRKSRC}/$i ${PREFIX}/bin
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's@:= -g -O@+= ${CFLAGS}@' -e "s@%%PREFIX%%@${PREFIX}@" ${WRKSRC}/Makefile

.include <bsd.port.mk>
