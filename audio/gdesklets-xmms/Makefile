# New ports collection makefile for:	gdesklets-xmms
# Date created:				4 January 2004
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmms
PORTVERSION=	2
PORTREVISION=	4
CATEGORIES=	audio gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-
EXTRACT_SUFX=	.tgz

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Compact desklet that allows you to control your XMMS from your desktop

RUN_DEPENDS=	gdesklets:${PORTSDIR}/deskutils/gdesklets

USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

NAME=		XMMS
WRKSRC=		${WRKDIR}/${NAME}
DATADIR=	${PREFIX}/share/gnome
PKGMESSAGE=	${WRKDIR}/pkg-message

# tarball inside of installator seems corrupted, ignore this error
post-patch:
	@${REINPLACE_CMD} -e "s|(fail)|(0)|" ${WRKSRC}/Install_${NAME}_Sensor.bin

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${CAT} pkg-message | ${SED} -e 's|%%PREFIX%%|${PREFIX}|g ; s|%%NAME%%|${NAME}|g' > ${PKGMESSAGE}
	@${REINPLACE_CMD} -e 's|/tmp|/var/tmp|' ${WRKSRC}/XMMS/xmmsint.py

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}/gfx
	@${MKDIR} ${DATADIR}/gdesklets/Sensors/${NAME}
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py ${DATADIR}/gdesklets/Sensors/${NAME}/
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/Display/*.display ${DATADIR}/gdesklets/Displays/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/Display/gfx/*.png ${DATADIR}/gdesklets/Displays/${NAME}/gfx/
	@${INSTALL_DATA} ${WRKSRC}/readme.txt ${DATADIR}/gdesklets/Displays/${NAME}/
	@${LN} -sf ${DATADIR}/gdesklets/Displays/${NAME}/readme.txt \
		${DATADIR}/gdesklets/Sensors/${NAME}/readme.txt
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
