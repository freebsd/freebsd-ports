# Created by: Serge Negodyuck <petr@petrovich.kiev.ua>
# $FreeBSD$

PORTNAME=	XnViewMP
PORTVERSION=	0.015
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp2.xnview.com/xnview/misc/
PKGNAMEPREFIX=	linux-
DISTNAME=	XnViewMP-linux
EXTRACT_SUFX=	.tgz

MAINTAINER=	petr@petrovich.kiev.ua
COMMENT=	XnView Multi Platform, graphics viewer and converter

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

NO_CDROM=	For commercial use and distribution, it is necessary to register
ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/XnViewMP

USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs

PLIST_FILES=	bin/xnview-mp lib/xnview-mp/libQtCore.so.4 \
		lib/xnview-mp/libQtGui.so.4 lib/xnview-mp/xnview

post-patch:
	@${REINPLACE_CMD} -e "s|\.|${PREFIX}/lib/xnview-mp|" ${WRKSRC}/xnview.sh

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/xnview-mp
	${INSTALL_SCRIPT} ${WRKSRC}/xnview.sh \
		${STAGEDIR}${PREFIX}/bin/xnview-mp
	${INSTALL_LIB} ${WRKSRC}/libQtCore.so.4 \
		${STAGEDIR}${PREFIX}/lib/xnview-mp
	${INSTALL_LIB} ${WRKSRC}/libQtGui.so.4 \
		${STAGEDIR}${PREFIX}/lib/xnview-mp
	${INSTALL_PROGRAM} ${WRKSRC}/xnview ${STAGEDIR}${PREFIX}/lib/xnview-mp

.include <bsd.port.mk>
