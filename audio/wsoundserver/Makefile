# New ports collection makefile for:	wmsound
# Version required:	0.9.0
# Date created:		9 December 1998
# Whom:			gljohns@bellsouth.net
#
# $Id: Makefile,v 1.1.1.1 1998/12/23 02:53:35 flathill Exp $
#

DISTNAME=	wmsound-0.9.0
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://www.frontiernet.net/~southgat/wmsound/download/

MAINTAINER=	gljohns@bellsouth.net

BUILD_DEPENDS=	wmaker:${PORTSDIR}/x11-wm/windowmaker

FETCH_BEFORE_ARGS=	-b

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-install:
	${SH} ${FILESDIR}/configure > ${WRKDIR}/WMSound
	${INSTALL_DATA} ${WRKDIR}/WMSound \
		${PREFIX}/share/WindowMaker/Defaults/WMSound
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
