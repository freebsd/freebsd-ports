# Created by: Shaun Amott <shaun@FreeBSD.org>
# $FreeBSD$

# Note: sdcard64.tar.gz contains just an empty 64MB FAT-16 disk image

PORTNAME=	x49gp
PORTVERSION=	20100425
PORTREVISION=	1
CATEGORIES=	emulators math
MASTER_SITES=	LOCAL/shaun
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} sdcard64.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	shaun@FreeBSD.org
COMMENT=	HP 49g+/50g graphics calculator emulator

BROKEN_i386=		does not build on i386 (error: frame pointer required, but reserved)

WRKSRC=		${WRKDIR}/x49gp/x49gp-code
HAVE_CONFIGURE=	yes

USE_GCC=	any
USE_XORG=	x11
USE_GNOME=	gtk20

USES=		gmake pkgconfig

OPTIONS_SINGLE=	FIRMWARE
OPTIONS_SINGLE_FIRMWARE=FIRMWARE_215 FIRMWARE_209
#OPTIONS_SINGLE_FIRMWARE=FIRMWARE_215H3 FIRMWARE_215 FIRMWARE_209

#FIRMWARE_215H3_DESC=	Calculator ROM firmware version 2.15 plus HPGCC3
FIRMWARE_215_DESC=	Calculator ROM firmware version 2.15
FIRMWARE_209_DESC=	Calculator ROM firmware version 2.09

OPTIONS_DEFINE=	GRAYSCALE
GRAYSCALE_DESC=	Apply patch for grayscale support

OPTIONS_DEFAULT=FIRMWARE_215 GRAYSCALE

SUB_FILES=	hp50g.sh

.if defined(WITH_DEBUG)
MAKE_ENV+=	DEBUGB=1
.endif

.include <bsd.port.options.mk>

MAKE_ARGS+=CC="${CC}"

.if ${PORT_OPTIONS:MGRAYSCALE}
EXTRA_PATCHES+=	${FILESDIR}/grayscale.diff
.endif

.if ${PORT_OPTIONS:MFIRMWARE_215H3} || ${PORT_OPTIONS:MFIRMWARE_215}
MAKE_ARGS+=FIRMWARE=4950_215.bin
DISTFILES+=hp4950v215.zip
EXTRACT_ONLY+=hp4950v215.zip
.else
MAKE_ARGS+=FIRMWARE=4950_92.bin
.endif

#.if ${PORT_OPTIONS:MFIRMWARE_215H3}
#DISTFILES+=rom215_hpgcc3_R004.tar.gz
#EXTRACT_ONLY+=rom215_hpgcc3_R004.tar.gz
#.endif

post-patch:
.if ${PORT_OPTIONS:MFIRMWARE_215H3} || ${PORT_OPTIONS:MFIRMWARE_215}
	@${CP} ${WRKDIR}/hp4950v215/*.lib ${WRKSRC}/
	@${CP} ${WRKDIR}/hp4950v215/*.bin ${WRKSRC}/
	@${CP} ${WRKDIR}/hp4950v215/*.scp ${WRKSRC}/
.endif
#.if ${PORT_OPTIONS:MFIRMWARE_215H3}
#	@${CP} ${WRKDIR}/rom215_hpgcc3_R004/hpgccrom.bin ${WRKSRC}/4950_215.bin
#.endif

do-configure:
	cd ${WRKSRC}/qemu/qemu-git && ./configure-small --extra-cflags=-DX49GP --cc="${CC}"

do-build:
	cd ${WRKSRC} && ${SETENV} -u MAKELEVEL -u MAKEFLAGS ${MAKE_CMD} ${MAKE_ARGS}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in flash-50g hp50g.png hp50g-hack.png hp49g+.png flash-49g+ sram s3c2410-sram
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}/
.endfor
	${INSTALL_DATA} ${FILESDIR}/config-hp50g ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${FILESDIR}/config-hp49g+ ${STAGEDIR}${DATADIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/x49gp ${STAGEDIR}${PREFIX}/bin/x49gp-bin

	${INSTALL_SCRIPT} ${WRKDIR}/hp50g.sh ${STAGEDIR}${PREFIX}/bin/hp50g
	${RM} ${STAGEDIR}${PREFIX}/bin/hp49g+
	${LN} ${STAGEDIR}${PREFIX}/bin/hp50g ${STAGEDIR}${PREFIX}/bin/hp49g+

	${INSTALL_DATA} ${DISTDIR}/sdcard64.tar.gz ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
