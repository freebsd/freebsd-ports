# New ports collection makefile for: wxftp
# Version required: 		0.4.4
# Date created: 		22 October 1998
# Whom: 			Antti Kaipila <anttik@iki.fi>
#
# $FreeBSD$
#

DISTNAME=	wxftp-0.4.4.src
PKGNAME=	wxftp-0.4.4
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.wxftp.seul.org/pub/wxftp/0.4.4/ \
		ftp://ftp.sunsite.auc.dk/disk2/linuxberg.com/files/x11/network/ \
		ftp://ftp.bitcon.no/.10/linux/linuxberg/files/x11/network/

MAINTAINER=	kris@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

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
