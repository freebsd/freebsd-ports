# New ports collection makefile for:	wmsound
# Version required:	0.9.0
# Date created:		9 December 1998
# Whom:			gljohns@bellsouth.net
#
# $Id: Makefile,v 1.3 1999/01/26 02:10:38 steve Exp $
#

DISTNAME=	wmsound-0.9.3
CATEGORIES=	audio windowmaker
MASTER_SITES=	ftp://shadowmere.student.utwente.nl/pub/WindowMaker/

MAINTAINER=	gljohns@bellsouth.net

BUILD_DEPENDS=	wmaker:${PORTSDIR}/x11-wm/windowmaker
LIB_DEPENDS=	PropList.1:${PORTSDIR}/devel/libPropList

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-install:
	${SH} ${FILESDIR}/configure > ${WRKDIR}/WMSound
	${MKDIR} ${PREFIX}/share/WindowMaker/Defaults
	${INSTALL_DATA} ${WRKDIR}/WMSound \
		${PREFIX}/share/WindowMaker/Defaults/WMSound
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
