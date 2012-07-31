# New ports collection makefile for:	libkexiv2
# Date created:				9 August 2011
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libkexiv2
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Exiv2 library interface for KDE

LIB_DEPENDS=	exiv2.12:${PORTSDIR}/graphics/exiv2

LATEST_LINK=	${PORTNAME}-kde4

CONFLICTS=	kdegraphics-4.[0-6].*

USE_XZ=	yes
USE_KDE4=	automoc4 kdehier kdeprefix kdelibs
KDE4_BUILDENV=	yes
USE_QT4=	dbus gui xml \
		moc_build qmake_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

pre-configure:
	${REINPLACE_CMD} -e '/pkgconfig/ s/$${LIB_INSTALL_DIR}/libdata/' \
		-e 's/${PORTNAME}.pc\([^.]\)/${PORTNAME}-kde4.pc\1/g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
