# New ports collection makefile for:	paintlib
# Version required:	0.2.1
# Date created:		04 Jan 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	paintlib.0.2.1
PKGNAME=	paintlib-0.2.1
CATEGORIES=	graphics devel
MASTER_SITES=	http://rio.xdev.org/paintlib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	will@FreeBSD.org

USE_QT2=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/paintlib
MAKE_ENV+=	PREFIX=${PREFIX} CXX=${CXX}
VERSION=	0
PLIST_SUB+=	VERSION=${VERSION}

post-patch:
	@${PERL} -pi -e "s:%%VERSION%%:${VERSION}:g" ${WRKSRC}/Makefile
	@${PERL} -pi -e "s:g\+\+:${CXX}:g" ${WRKSRC}/Makefile

do-install:
	@${INSTALL_DATA} ${WRKSRC}/PaintLib.h ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/libPaintLib.so.${VERSION} ${PREFIX}/lib
	@${LN} -sf libPaintLib.so.${VERSION} ${PREFIX}/lib/libPaintLib.so
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
