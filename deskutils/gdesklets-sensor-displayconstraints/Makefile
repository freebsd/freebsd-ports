# New ports collection makefile for:	gdesklets-displayconstraints
# Date created:				06 January 2004
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	displayconstraints
PORTVERSION=	0.1.0
PORTREVISION=	3
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-sensor-
DISTNAME=	displayconstraints-${PORTVERSION}

MAINTAINER=	klammer@webonaut.com
COMMENT=	This Sensor allows a user to set maximum constraints on a display

DEPRECATED=	dead project and not fetchable any more
EXPIRATION_DATE=2006-10-12

RUN_DEPENDS=	gdesklets:${PORTSDIR}/deskutils/gdesklets

WRKSRC=		${WRKDIR}/${NAME}-${PORTVERSION}

USE_BZIP2=	yes
USE_XLIB=	yes
USE_PYTHON=	yes
NAME=		DisplayConstraints

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
	@${MKDIR} ${PREFIX}/share/gnome/gdesklets/Sensors/${NAME}
	${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py ${PREFIX}/share/gnome/gdesklets/Sensors/${NAME}/
	${INSTALL_DATA} ${WRKSRC}/${NAME}/README ${PREFIX}/share/gnome/gdesklets/Sensors/${NAME}/
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/share/gnome/gdesklets/Sensors/${NAME}/
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/share/gnome/gdesklets/Sensors/${NAME}/

.include <bsd.port.mk>
