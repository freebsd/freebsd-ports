# $FreeBSD$

PORTNAME=	smokegen
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde kde-kde4
MAINTAINER=	kde@FreeBSD.org
COMMENT=	SMOKE bindings for KDE

USES=		cmake:outsource kde:4 tar:xz
USE_QT4=	corelib xml qmake_build moc_build uic_build rcc_build
CMAKE_ARGS+=	-DSMOKE_CMAKE_MODULE_DIR:PATH=${PREFIX}/lib/cmake/smoke
USE_LDCONFIG=	yes

pre-configure:
	${REINPLACE_CMD} -e 's|share/smoke/cmake|lib/cmake/smoke|g' \
		${WRKSRC}/smokebase/CMakeLists.txt

.include <bsd.port.mk>
