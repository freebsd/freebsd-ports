# New ports collection makefile for:	gdesklets-sensor-psi_memoover
# Date created:				20 September 2003
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	memoover
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-sensor-psi_
DISTNAME=	PsiSensorPackage-${DISTVERSION}

MAINTAINER=	klammer@webonaut.com
COMMENT=	MemoOver Sensor from the Psi Sensor Package

RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gdesklets-core.pc:${PORTSDIR}/deskutils/gdesklets

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_X_PREFIX=	yes

DISTVERSION=	20031028
NAME=		MemoOver
DATADIR=	${PREFIX}/share/gnome
WRKSRC=		${WRKDIR}/${NAME}-${PORTVERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/${NAME}

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Sensors/${NAME}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py ${DATADIR}/gdesklets/Sensors/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}/gdesklets/Sensors/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/*.py ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/INSTALLATION ${EXAMPLESDIR}

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${NAME}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${NAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
