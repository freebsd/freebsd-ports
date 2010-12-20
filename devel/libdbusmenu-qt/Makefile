# New ports collection makefile for:	libdbusmenu-qt
# Date created:				2010-05-10
# Whom:					Dima Panov <fluffy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdbusmenu-qt
PORTVERSION=	0.6.6
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt4 implementation of the DBusMenu protocol

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

FETCH_ARGS=	-Fpr
USE_BZIP2=	yes
USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	dbus gui xml \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

CMAKE_OUTSOURCE=	yes
MAKE_JOBS_SAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e '/pkgconfig/ s/$${LIB_SUFFIX}/data/' \
		-e '/tests/ d' -e '/tools/ d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
