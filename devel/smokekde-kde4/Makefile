# $FreeBSD$

PORTNAME=	smokekde
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	4
CATEGORIES=	devel kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	SMOKE bindings for KDE

USES=		cmake:outsource kde:4 tar:xz
USE_KDE=	kate kdelibs okular pimlibs \
		smokegen smokeqt akonadi automoc4 soprano
USE_QT4=	corelib dbus designer_build gui network opengl sql svg xml \
		qmake_build moc_build uic_build rcc_build
USE_LDCONFIG=	yes
USE_CXXSTD=	gnu++98

OPTIONS_DEFINE=	ATTICA
OPTIONS_SUB=	yes
# Attica bindings often cause the build to coredump.
ATTICA_DESC=	Bindings for libattica (may crash build)
ATTICA_CMAKE_OFF=	-DWITH_LibAttica:BOOL=FALSE

pre-configure:
	${REINPLACE_CMD} -e '/kde-config.xml/ s|$${SMOKE_GEN_BIN}|smokegen|' \
		${WRKSRC}/kdecore/CMakeLists.txt

.include <bsd.port.mk>
