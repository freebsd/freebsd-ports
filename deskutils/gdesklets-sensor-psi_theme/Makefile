# New ports collection makefile for:	gdesklets-sensor-psi_theme
# Date created:				20 September 2003
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	theme
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-sensor-psi_
DISTNAME=	PsiSensorPackage-${DISTVERSION}

MAINTAINER=	klammer@webonaut.com
COMMENT=	Theme Sensor from the Psi Sensor Package

RUN_DEPENDS=	gdesklets:${PORTSDIR}/deskutils/gdesklets \
		${DATADIR}/gdesklets/Themes/Psi-Disp-Themes/icons/themes:${PORTSDIR}/deskutils/gdesklets-psi_themes

USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

DISTVERSION=	20040420
NAME=		Theme
DATADIR=	${PREFIX}/share/gnome
WRKSRC=		${WRKDIR}/${NAME}-${PORTVERSION}

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${REINPLACE_CMD} -e 's|/usr/share/gdesklets/Themes/|${DATADIR}/gdesklets/Themes/|' \
		${WRKSRC}/${NAME}/__init__.py
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${FIND} ${WRKSRC} -name '*.bak' -delete

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Sensors/${NAME}
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py ${DATADIR}/gdesklets/Sensors/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}/gdesklets/Sensors/${NAME}/

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${NAME}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${NAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
