# New ports collection makefile for:	xamp
# Date created:			29 July 1998
# Whom:				Joe Jih-Shian Lu <jslu@dns.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	xamp
PORTVERSION=	0.8.10
CATEGORIES=	audio
MASTER_SITES=	http://andrej.co.ru/~andrej/programs/xamp/ \
		http://andrej.co.ru/~andrej/programs/xamp/backs/
DISTFILES=	${PORTNAME}-0.8-10.tgz ${SKIN_DATA}

MAINTAINER=	ports@FreeBSD.org

USE_GMAKE=	YES
WRKSRC=		${WRKDIR}/${PORTNAME}-0.8/${PORTNAME}-0.8g/
DIST_SUBDIR=	xamp
USE_QT_VER=	1
USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
MAN1=		xamp.1
SKIN_DATA=	bfamp.tar.gz chrome.tar.gz mmxamp.tar.gz
SKIN_DIR=	${PREFIX}/lib/X11/xamp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xamp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xamp.1 ${PREFIX}/man/man1
	@${MKDIR} ${SKIN_DIR}/bfamp-xamp
	${INSTALL_DATA} ${WRKDIR}/bfamp-xamp/*.bmp ${SKIN_DIR}/bfamp-xamp
	@${MKDIR} ${SKIN_DIR}/chrome-xamp
	${INSTALL_DATA} ${WRKDIR}/chrome-xamp/*.bmp ${SKIN_DIR}/chrome-xamp
	@${MKDIR} ${SKIN_DIR}/mmxxamp-xamp
	${INSTALL_DATA} ${WRKDIR}/mmxxamp-xamp/*.bmp ${SKIN_DIR}/mmxxamp-xamp

.include <bsd.port.mk>
