# Created by: dk
# $FreeBSD$

PORTNAME=	fmsx
PORTVERSION=	5.4
CATEGORIES=	emulators
MASTER_SITES=	http://fms.komkon.org/fMSX/:code \
		http://fms.komkon.org/fMSX/src/:rom
DISTFILES=	fMSX${PORTVERSION:C/\.//}.zip:code \
		MSX.ROM:rom MSX2.ROM:rom MSX2EXT.ROM:rom MSX2P.ROM:rom \
		MSX2PEXT.ROM:rom FMPAC.ROM:rom DISK.ROM:rom MSXDOS2.ROM:rom \
		PAINTER.ROM:rom KANJI.ROM:rom
DIST_SUBDIR=	fmsx5
EXTRACT_ONLY=	fMSX${PORTVERSION:C/\.//}.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable MSX/MSX2/MSX2+ Emulator

LICENSE=	UNKNOWN
LICENSE_NAME=	unknown
LICENSE_TEXT=	This program is NOT in public domain.\
		It can be freely distributed for non-commercial purposes only. \
		Legal status of distributed ROM images is unclear.
LICENSE_PERMS=	none

USES=		dos2unix gmake xorg zip
USE_XORG=	x11 xext
DOS2UNIX_FILES=	EMULib/Unix/LibUnix.c EMULib/Unix/NetUnix.c EMULib/Rules.gcc \
		EMULib/Rules.Unix fMSX/fMSX.html

NO_WRKSUBDIR=	yes
SUB_FILES=	${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/fMSX/Unix

OPTIONS_DEFINE=	DOCS PULSEAUDIO
OPTIONS_SINGLE=	BPP
OPTIONS_SINGLE_BPP=	BPP8 BPP16 BPP24 BPP32
OPTIONS_DEFAULT=	BPP32
BPP8_DESC=	With BPP8
BPP16_DESC=	With BPP16
BPP24_DESC=	With BPP24
BPP32_DESC=	With BPP32 (see pkg-message)
BPP8_CFLAGS=	-DBPP8
BPP16_CFLAGS=	-DBPP16
BPP24_CFLAGS=	-DBPP24
BPP32_CFLAGS=	-DBPP32
PULSEAUDIO_CFLAGS=	-DPULSE_AUDIO
PULSEAUDIO_LIB_DEPENDS=	libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_LIBS=	-lpulse-simple

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/fmsx ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fMSX/Unix/fmsx ${STAGEDIR}${PREFIX}/libexec/fmsx
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.ROM ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/fMSX/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
