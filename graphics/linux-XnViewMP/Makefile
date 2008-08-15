# New ports collection makefile for:	xnview-mp
# Date created:				23 Jul 2008
# Whom:					Serge Negodyuck <petr@petrovich.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	XnViewMP
PORTVERSION=	0.015
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp2.xnview.com/xnview/misc/
PKGNAMEPREFIX=	linux-
DISTNAME=	XnViewMP-linux
EXTRACT_SUFX=	.tgz

MAINTAINER=	petr@petrovich.kiev.ua
COMMENT=	XnView Multi Platform, graphics viewer and converer

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libglib-2.0.so.0:${PORTSDIR}/devel/linux-glib2

NO_CDROM=	For commercial use and distribution, it is necessary to register
ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/XnViewMP

USE_LINUX=	yes
USE_XLIB=	yes

PLIST_FILES=	bin/xnview-mp lib/xnview-mp/libQtCore.so.4 \
		lib/xnview-mp/libQtGui.so.4 lib/xnview-mp/xnview
PLIST_DIRS=	lib/xnview-mp

post-patch:
	@${REINPLACE_CMD} -e "s|\.|${PREFIX}/lib/xnview-mp|" ${WRKSRC}/xnview.sh

do-install:
	${MKDIR}	${PREFIX}/lib/xnview-mp
	${INSTALL_SCRIPT} ${WRKSRC}/xnview.sh	${PREFIX}/bin/xnview-mp
	${INSTALL_PROGRAM}	${WRKSRC}/libQtCore.so.4	${PREFIX}/lib/xnview-mp/
	${INSTALL_PROGRAM} ${WRKSRC}/libQtGui.so.4		${PREFIX}/lib/xnview-mp/
	${INSTALL_PROGRAM} 	${WRKSRC}/xnview	${PREFIX}/lib/xnview-mp/

.include <bsd.port.mk>
