# New ports collection makefile for:	gdesklets-sensor-psi_memo
# Date created:				20 September 2003
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	memo
PORTVERSION=	0.1.5
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-sensor-psi_
DISTNAME=	PsiSensorPackage-${DISTVERSION}

MAINTAINER=	klammer@webonaut.com
COMMENT=	Memo Sensor from the Psi Sensor Package

RUN_DEPENDS=	gdesklets:${PORTSDIR}/deskutils/gdesklets

USE_PYTHON=	yes
USE_X_PREFIX=	yes

DISTVERSION=	20040420
NAME=		Memo
DATADIR=	${PREFIX}/share/gnome
WRKSRC=		${WRKDIR}/${NAME}-${PORTVERSION}

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Sensors/${NAME}
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py ${DATADIR}/gdesklets/Sensors/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}/gdesklets/Sensors/${NAME}/

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${NAME}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${NAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
