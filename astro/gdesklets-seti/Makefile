# New ports collection makefile for:	gdesklets-seti
# Date created:				12 November 2003
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	seti
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	astro gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	klammer@webonaut.com
COMMENT=	Simple but useful setidesklet with less CPU-usage

RUN_DEPENDS=	gdesklets:${PORTSDIR}/deskutils/gdesklets

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_PYTHON=	yes
NAME=		Seti

do-build:
	@${WRKDIR}/Install_${NAME}_Sensor.bin --nomsg ${WRKDIR}/${PORTNAME}
	@${REINPLACE_CMD} -e 's|/usr/setiathome|/var/db/setiathome|g' \
		${WRKDIR}/${PORTNAME}/${NAME}/sah.py
	@${FIND} ${WRKDIR}/${PORTNAME} -name '*.bak' -delete

do-install:
	@${MKDIR} ${PREFIX}/share/gnome/gdesklets/Displays/${NAME}/gfx
	@${MKDIR} ${PREFIX}/share/gnome/gdesklets/Sensors/${NAME}
	@${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/*.display ${PREFIX}/share/gnome/gdesklets/Displays/${NAME}/
	@${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/gfx/*.png ${PREFIX}/share/gnome/gdesklets/Displays/${NAME}/gfx/
	@${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/${NAME}/*.py ${PREFIX}/share/gnome/gdesklets/Sensors/${NAME}/

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/share/gnome/gdesklets/Sensors/${NAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
