# New ports collection makefile for:	gdesklets-irc
# Date created:		6 May 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	irc
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	irc gnome deskutils
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-

MAINTAINER=	perky@FreeBSD.org
COMMENT=	An IRC display and sensor for gdesklets

RUN_DEPENDS=	gdesklets:${PORTSDIR}/deskutils/gdesklets \
		${PYTHON_SITELIBDIR}/twisted/__init__.py:${PORTSDIR}/devel/py-twisted

USE_PYTHON=	yes
USE_X_PREFIX=	yes

NAME=		irc
DATADIR=	${PREFIX}/share/gnome/gdesklets
LANG=		ko
PKGMESSAGE=	${WRKDIR}/pkg-message
WRKSRC=		${WRKDIR}/${NAME}

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${CAT} pkg-message | ${SED} -e 's|%%PREFIX%%|${PREFIX}|g ; s|%%NAME%%|${NAME}|g' > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${DATADIR}/Displays/${NAME}/gfx
	@${MKDIR} ${DATADIR}/Sensors/${NAME}/gfx
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py ${DATADIR}/Sensors/${NAME}/
.for ii in ${LANG}
	@${MKDIR} ${DATADIR}/Sensors/${NAME}/locale/${ii}/LC_MESSAGES
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/locale/${ii}/LC_MESSAGES/*.mo \
		${DATADIR}/Sensors/${NAME}/locale/${ii}/LC_MESSAGES/
.endfor
	@${INSTALL_DATA} ${WRKSRC}/*.display ${DATADIR}/Displays/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/gfx/*.png ${DATADIR}/Displays/${NAME}/gfx/

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/Sensors/${NAME}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/Sensors/${NAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
