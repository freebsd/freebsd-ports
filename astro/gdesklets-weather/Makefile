# New ports collection makefile for:	gdesklets-weather
# Date created:				17 November 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	weather
PORTVERSION=	0.24
PORTREVISION=	1
CATEGORIES=	astro gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	weather-desklet-${PORTVERSION}

MAINTAINER=	mezz7@cox.net
COMMENT=	A weather monitoring Sensor and Display for gdesklets

RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gdesklets-core.pc:${PORTSDIR}/deskutils/gdesklets

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

NAME=		Weather
DATADIR=	${PREFIX}/share/gnome
PKGMESSAGE=	${WRKDIR}/pkg-message

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${CAT} pkg-message | ${SED} -e 's|%%PREFIX%%|${PREFIX}|g ; s|%%NAME%%|${NAME}|g' > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}/gfx
	@${MKDIR} ${DATADIR}/gdesklets/Sensors/${NAME}/icons
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py ${DATADIR}/gdesklets/Sensors/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/icons/*.png ${DATADIR}/gdesklets/Sensors/${NAME}/icons/
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
