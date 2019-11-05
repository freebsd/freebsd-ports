# Created by: Thomas Bernard <nanard@free.fr>
# $FreeBSD$

PORTNAME=	teo
PORTVERSION=	1.8.4
DISTVERSIONSUFFIX=	-src
CATEGORIES=	emulators
MASTER_SITES=	SF/teoemulator/linux/${PORTVERSION}

MAINTAINER=	nanard@free.fr
COMMENT=	Thomson TO8 emulator

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/licence-en.txt

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libpng.so:graphics/png

USES=		gmake gnome pkgconfig xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_XORG=	x11 xext

ALL_TARGET=	default
WRKSRC=		${WRKDIR}/teo

post-patch:
	@${ECHO_CMD} "MAKEFILE_INC = makefile.lnx" > ${WRKSRC}/Makefile
	@${ECHO_CMD} "include makefile.all" >> ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|"system/|"${DATADIR}/|' \
		 ${WRKSRC}/src/hardware.c ${WRKSRC}/src/linux/udebug/udtoolb.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/teo ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/rom
	${INSTALL_DATA} ${WRKSRC}/system/rom/* ${STAGEDIR}${DATADIR}/rom
	@${MKDIR} ${STAGEDIR}${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/system/icons/* ${STAGEDIR}${DATADIR}/icons

.include <bsd.port.mk>
