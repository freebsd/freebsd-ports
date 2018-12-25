# $FreeBSD$

PORTNAME=	okteta
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	5
CATEGORIES=	devel kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE hex editor

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libqca.so:devel/qca@qt4

USES=		cmake kde:4 qt:4 shared-mime-info tar:xz
USE_KDE=	kdelibs automoc4
USE_QT=		moc_build qmake_build rcc_build uic_build \
		corelib designer gui script scripttools xml
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d; /SharedMimeInfo/ d' \
		${PATCH_WRKSRC}/mimetypes/CMakeLists.txt

.include <bsd.port.mk>
