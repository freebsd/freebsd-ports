# New ports collection makefile for: wxftp
# Version required: 		0.4.1
# Date created: 		22 October 1998
# Whom: 			Antti Kaipila <anttik@iki.fi>
#
# $Id: Makefile,v 1.2 1999/01/18 03:26:43 steve Exp $
#

DISTNAME=	wxftp-0.4.1.src
PKGNAME=	wxftp-0.4.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR= 	system/network/file-transfer

MAINTAINER=	anttik@iki.fi

LIB_DEPENDS=	gtk10.1:${PORTSDIR}/x11-toolkits/gtk10

WRKSRC=		${WRKDIR}/${PKGNAME}/src
USE_GMAKE=	yes
USE_X_PREFIX=	yes

MAN1=		wxftp.1

post-build:

	@${CP} ${WRKSRC}/wf ${WRKDIR}/${PKGNAME}/wxftp

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${PKGNAME}/wxftp ${PREFIX}/bin
	@${CP} ${WRKDIR}/${PKGNAME}/wxftp.1X ${WRKDIR}/${PKGNAME}/wxftp.1
	${INSTALL_MAN} ${WRKDIR}/${PKGNAME}/wxftp.1 ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/share/wxftp/help
	${INSTALL_DATA} ${WRKDIR}/${PKGNAME}/help/*  ${PREFIX}/share/wxftp/help

.include <bsd.port.mk>
