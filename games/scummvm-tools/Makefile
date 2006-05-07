# New ports collection makefile for:	scummvm-tools
# Date created:				28 May 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scummvm-tools
PORTVERSION=	0.8.0
CATEGORIES=	games emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	scummvm

MAINTAINER=	freebsd.alex@trull.org
COMMENT=	Tools for use with the SCUMMVM game emulator

RUN_DEPENDS=	scummvm:${PORTSDIR}/games/scummvm
BUILD_DEPENDS=	lame:${PORTSDIR}/audio/lame \
		flac:${PORTSDIR}/audio/flac \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		oggdec:${PORTSDIR}/audio/vorbis-tools

USE_BZIP2=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/tools-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.3+
.endif

do-install:
.for i in compress_queen compress_saga compress_san compress_scumm_bun compress_scumm_sou compress_simon compress_sword1 compress_sword2 extract_kyra extract_loom_tg16 extract_mm_c64 extract_mm_nes extract_scumm_mac extract_simon1_amiga extract_zak_c64 dekyra descumm desword2
	@${INSTALL_PROGRAM} ${WRKSRC}/$i ${PREFIX}/bin
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's@:= -g -O@+= ${CFLAGS}@' ${WRKSRC}/Makefile
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's/gcc/${CC}/g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's/g\+\+/g\+\+32/g' ${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>
