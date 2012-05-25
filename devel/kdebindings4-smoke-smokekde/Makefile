# New ports collection makefile for:	kdebindings4-smoke
# Date created:		2008-08-19
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	smokekde
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	kdebindings-smoke-
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	SMOKE bindings for KDE

CONFLICTS=	kdebindings-smoke-4.[0-6].*

USE_KDE4=	kate kdehier kdelibs kdeprefix okular pimlibs \
		smokegen smokeqt akonadi automoc4 soprano
USE_QT_VER=	4
QT_COMPONENTS=	dbus designer gui network opengl qt3support sql svg xml \
		qmake_build moc_build uic_build rcc_build
USE_XZ=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

OPTIONS=	ATTICA "Bindings for libattica (may crash build)" off

.include <bsd.port.options.mk>

# Attica bindings often cause the build to coredump.
.ifdef(WITH_ATTICA)
PLIST_SUB+=	ATTICA=""
.else
CMAKE_ARGS+=	-DWITH_LibAttica:BOOL=FALSE
PLIST_SUB+=	ATTICA="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} -e '/kde-config.xml/ s|$${SMOKE_GEN_BIN}|smokegen|' \
		${WRKSRC}/kdecore/CMakeLists.txt

.include <bsd.port.mk>
