# New ports collection makefile for:    xnview
# Date created:         9 Jul 2002
# Whom:                 
#
# $FreeBSD$
#

PORTNAME=	xnview
PORTVERSION=   	1.25
CATEGORIES=	graphics
MASTER_SITES=  	http://perso.wanadoo.fr/pierre.g/download/viewer/ \
		ftp://www.zoo-logique.org/xnview/download/
DISTNAME=       XnView-x86-unknown-FreeBSD3.x
EXTRACT_SUFX=	.tgz

MAINTAINER=	petr@petrovich.kiev.ua

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
USE_X_PREFIX=	yes
USE_MOTIF=	yes
WRKSRC=		${WRKDIR}/XnView-1.25-x86-unknown-FreeBSD3.x
INSTALL_SLIB=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/xnview ${PREFIX}/bin/xnview
	${INSTALL_PROGRAM} ${WRKSRC}/bin/nview ${PREFIX}/bin/nv
	${INSTALL_PROGRAM} ${WRKSRC}/bin/nconvert ${PREFIX}/bin/nconvert	
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libformat.so.3.16 ${PREFIX}/lib/libformat.so
	${INSTALL_DATA} ${WRKSRC}/app-defaults/XnView.ad ${PREFIX}/lib/X11/app-defaults/XnView
	${MKDIR} ${PREFIX}/share/doc/xnview
	cd ${WRKSRC} && \
		${INSTALL_DATA} Formats.txt ReadMe.txt Usage.txt WhatsNew.txt \
		${PREFIX}/share/doc/xnview

.include <bsd.port.mk>
