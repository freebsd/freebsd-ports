# New ports collection makefile for:	gdesklets-goodweather
# Date created:				17 November 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	goodweather
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	astro gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	GoodWeather-${PORTVERSION}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	A desklet that displays current weather condition and forecast

RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gdesklets-core.pc:${PORTSDIR}/deskutils/gdesklets

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

NAME=		GoodWeather
WRKSRC=		${WRKDIR}/${NAME}
DATADIR=	${PREFIX}/share/gnome
PKGMESSAGE=	${WRKDIR}/pkg-message
SKINS=		liquid um weather.com

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}/gfx
.for ii in ${SKINS}
	@${MKDIR} ${DATADIR}/gdesklets/Sensors/${NAME}/${ii}/large_icons
	@${MKDIR} ${DATADIR}/gdesklets/Sensors/${NAME}/${ii}/small_icons
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/${ii}/large_icons/*.png \
		${DATADIR}/gdesklets/Sensors/${NAME}/${ii}/large_icons/
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/${ii}/small_icons/*.png \
		${DATADIR}/gdesklets/Sensors/${NAME}/${ii}/small_icons/
.endfor
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py ${DATADIR}/gdesklets/Sensors/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/*.display ${DATADIR}/gdesklets/Displays/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/gfx/*.png ${DATADIR}/gdesklets/Displays/${NAME}/gfx/
	@${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}/gdesklets/Displays/${NAME}/
	@${LN} -s ${DATADIR}/gdesklets/Displays/${NAME}/README \
		${DATADIR}/gdesklets/Sensors/${NAME}/README

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${NAME}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${NAME}
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g ; s|%%NAME%%|${NAME}|g' \
		${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
