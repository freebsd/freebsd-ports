# New ports collection makefile for:	gdesklets-goodweather
# Date created:				17 November 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	goodweather
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	astro gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/ \
		http://people.roqe.org/kr/misc/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	GoodWeather-${PORTVERSION}

MAINTAINER=	mezz7@cox.net
COMMENT=	A desklet that displays current weather condition and forecast

RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gdesklets-core.pc:${PORTSDIR}/deskutils/gdesklets

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

NAME=		GoodWeather
DATADIR=	${PREFIX}/share/gnome
SKINS=		liquid um weather.com

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${PATCH} ${WRKSRC}/${NAME}/__init__.py < ${FILESDIR}/${NAME}::__init__.py
	@${PATCH} ${WRKSRC}/${NAME}/weather.py < ${FILESDIR}/${NAME}::weather.py
	@${FIND} ${WRKSRC} -name '*.orig' -delete

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
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
