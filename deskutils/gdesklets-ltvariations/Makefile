# New ports collection makefile for:	gdesklets-ltvariations
# Date created:				20 March 2004
# Whom:					Tim Bishop <tim@bishnet.net>
#
# $FreeBSD$
#

PORTNAME=	ltvariations
PORTVERSION=	0.26
PORTREVISION=	8
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	LTVariations-${PORTVERSION}

MAINTAINER=	tim@bishnet.net
COMMENT=	A collection of sensors and displays

RUN_DEPENDS=	gdesklets:${PORTSDIR}/deskutils/gdesklets

USE_PYTHON=	yes
USE_X_PREFIX=	yes

SENSORS=	LTVMemory LTVFontSelector LTVUptime LTVBorder LTVClock \
		LTVCommand LTVCpu LTVDisk
DISPLAY=	LTCandy

WRKSRC=		${WRKDIR}
DATADIR=	${PREFIX}/share/gnome
PKGMESSAGE=	${WRKDIR}/pkg-message

do-build:
.for ii in ${SENSORS}
	@${WRKSRC}/Sensors/Install_${ii}_Sensor.bin --nomsg ${WRKSRC}
.endfor
	@${PATCH} ${WRKSRC}/LTVUptime/__init__.py < ${FILESDIR}/LTVUptime::__init__.py
	@${PATCH} ${WRKSRC}/LTVClock/__init__.py < ${FILESDIR}/LTVClock::__init__.py
	@${CAT} pkg-message | ${SED} -e 's|%%PREFIX%%|${PREFIX}|g ; s|%%DISPLAY%%|${DISPLAY}|g' > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${DISPLAY}/gfx/bg
.for ii in ${SENSORS}
	@${MKDIR} ${DATADIR}/gdesklets/Sensors/${ii}
	@${INSTALL_DATA} ${WRKSRC}/${ii}/*.py ${DATADIR}/gdesklets/Sensors/${ii}/
.endfor
	@${INSTALL_DATA} ${WRKSRC}/LTVClock/timezones.dat ${DATADIR}/gdesklets/Sensors/LTVClock/
	@${INSTALL_DATA} ${WRKSRC}/Displays/${DISPLAY}/*.display ${DATADIR}/gdesklets/Displays/${DISPLAY}/
	@${INSTALL_DATA} ${WRKSRC}/Displays/${DISPLAY}/gfx/*.png ${DATADIR}/gdesklets/Displays/${DISPLAY}/gfx/
	@${INSTALL_DATA} ${WRKSRC}/Displays/${DISPLAY}/gfx/bg/*.png ${DATADIR}/gdesklets/Displays/${DISPLAY}/gfx/bg/

post-install:
.for ii in ${SENSORS}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${ii}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${ii}
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
