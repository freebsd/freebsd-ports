# New ports collection makefile for:	kdissert
# Date created:				2004 06 July
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdissert
PORTVERSION=	0.2.9
CATEGORIES=	deskutils kde
MASTER_SITES=	http://freehackers.org/~tnagy/kdissert/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE mindmapping tool

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_BZIP2=	yes
USE_KDELIBS_VER=	3
USE_REINPLACE=	yes
USE_GMAKE=	yes
WANT_LIBTOOL_VER=	15
MAKE_ARGS=	QTDIR="${QT_PREFIX}" LIBTOOL="${LIBTOOL} --tag=CXX"
INSTALLS_SHLIB=	yes

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ main.pro

pre-install:
	@${MKDIR} ${PREFIX}/share/apps/kdissert/pics
	@${MKDIR} ${PREFIX}/share/apps/kdissert/templatedata
	@${MKDIR} ${PREFIX}/share/doc/HTML/en/kdissert
.for size in 16 32 64 128
	@${MKDIR} ${PREFIX}/share/icons/hicolor/${size}x${size}/apps
.endfor

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/kdissert

.include <bsd.port.mk>
