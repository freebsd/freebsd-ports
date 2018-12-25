# $FreeBSD$

PORTNAME=	smokegen
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-kde4
MAINTAINER=	kde@FreeBSD.org
COMMENT=	SMOKE bindings for KDE

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

USES=		cmake kde:4 qt:4 tar:xz
USE_QT=		corelib xml qmake_build moc_build uic_build rcc_build
CMAKE_ARGS+=	-DSMOKE_CMAKE_MODULE_DIR:PATH=${PREFIX}/lib/cmake/smoke
USE_LDCONFIG=	yes

pre-configure:
	${REINPLACE_CMD} -e 's|share/smoke/cmake|lib/cmake/smoke|g' \
		${WRKSRC}/smokebase/CMakeLists.txt

.include <bsd.port.mk>
