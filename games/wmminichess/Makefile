# New ports collection makefile for:	(wm)miniCHESS
# Version required:	0.8
# Date created:		24 Sep 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	miniCHESS-0.8
PKGNAME=	wmminichess-0.8
CATEGORIES=	games
MASTER_SITES=	http://www.electricrain.com/edavis/miniCHESS/

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm
RUN_DEPENDS=	${LOCALBASE}/bin/gnuchessx:${PORTSDIR}/games/gnuchess

USE_GMAKE=	YES
USE_X_PREFIX=	YES
MAKE_ENV=	PREFIX="${PREFIX}" INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		LOCAL="${LOCALBASE}" MKDIR="${MKDIR}" \
		INSTALL_DATA="${INSTALL_DATA}"

.include <bsd.port.mk>
