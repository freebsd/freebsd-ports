# New ports collection makefile for:	libkdcraw-kde4
# Date created:			Sat 13 Aug 2011, 23:48:30
# Whom:				Dima Panov <fluffy@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libkdcraw
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	A LibRaw interface for KDE

LIB_DEPENDS=	lcms.1:${PORTSDIR}/graphics/lcms

LATEST_LINK=	${PORTNAME}-kde4

CONFLICTS=	kdegraphics-4.[0-6].*

USE_BZIP2=	yes
USE_KDE4=	automoc4 kdehier kdeprefix kdelibs
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	dbus gui xml \
		moc_build qmake_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

pre-configure:
	${REINPLACE_CMD} -e '/pkgconfig/ s/$${LIB_INSTALL_DIR}/libdata/' \
		-e 's/${PORTNAME}.pc\([^.]\)/${PORTNAME}-kde4.pc\1/g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
