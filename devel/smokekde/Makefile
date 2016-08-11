# $FreeBSD$

PORTNAME=	smokekde
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	SMOKE bindings for KDE

USE_KDE4=	kate kdelibs okular pimlibs \
		smokegen smokeqt akonadi automoc4 soprano
USE_QT4=	corelib dbus designer_build gui network opengl sql svg xml \
		qmake_build moc_build uic_build rcc_build
USES=		cmake:outsource tar:xz
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	ATTICA
OPTIONS_SUB=	yes
# Attica bindings often cause the build to coredump.
ATTICA_DESC=	Bindings for libattica (may crash build)
ATTICA_CMAKE_OFF=	-DWITH_LibAttica:BOOL=FALSE

pre-configure:
	${REINPLACE_CMD} -e '/kde-config.xml/ s|$${SMOKE_GEN_BIN}|smokegen|' \
		${WRKSRC}/kdecore/CMakeLists.txt

.include <bsd.port.mk>
