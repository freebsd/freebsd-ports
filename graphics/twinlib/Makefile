# New ports collection makefile for:	twinlib
# Date created:		04 Jan 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	twinlib
PORTVERSION=	0.2.3
CATEGORIES=	graphics devel
MASTER_SITES=	http://rio.xdev.org/twinlib/
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	will@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/bin/tmake:${PORTSDIR}/devel/tmake

USE_QT=		yes
USE_X_PREFIX=	yes
INSTALL_SHLIBS=	yes
WRKSRC=		${WRKDIR}/twinlib
MAKE_ENV+=	PREFIX=${PREFIX} CXX=${CXX}
VERSION=	0
PLIST_SUB+=	VERSION=${VERSION}
MAKE_ENV+=	TMAKEPATH="${LOCALBASE}/share/tmake/freebsd-g++" \
		QTDIR="${X11BASE}"

do-install:
	@${INSTALL_DATA} ${WRKSRC}/TwinLib.h ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/libTwinlib.so.${PORTVERSION} ${PREFIX}/lib/libTwinlib.so.${VERSION}
	@${LN} -sf ${PREFIX}/libTwinlib.so.${VERSION} ${PREFIX}/lib/libTwinlib.so

.include <bsd.port.mk>
