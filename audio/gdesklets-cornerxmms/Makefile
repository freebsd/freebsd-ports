# New ports collection makefile for:	gdesklets-cornerxmms
# Date created:				22 December 2003
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	cornerxmms
PORTVERSION=	0.0.5
PORTREVISION=	1
CATEGORIES=	audio gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	CornerXMMS-${PORTVERSION}

MAINTAINER=	klammer@webonaut.com
COMMENT=	A fancy desklet that allows you to control XMMS from the desktop

RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gdesklets-core.pc:${PORTSDIR}/deskutils/gdesklets \
		${PYTHON_SITELIBDIR}/xmms/__init__.py:${PORTSDIR}/audio/py-xmms

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_X_PREFIX=	yes

NAME=		CornerXMMS
DATADIR=	${PREFIX}/share/gnome
WRKSRC=		${WRKDIR}/${NAME}-${PORTVERSION}

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Sensors/${NAME}
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}/gfx
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py ${DATADIR}/gdesklets/Sensors/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}/gdesklets/Sensors/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/*.display ${DATADIR}/gdesklets/Displays/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/gfx/*.png ${DATADIR}/gdesklets/Displays/${NAME}/gfx/

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${NAME}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${NAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
