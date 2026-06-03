PORTNAME=	optiimage
PORTVERSION=	1.0.0
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/optiimage

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Image optimizer
WWW=		https://apps.kde.org/optiimage/

LIB_DEPENDS=	libQCoro6Core.so:devel/qcoro

USES=		cmake compiler:c++20-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	config coreaddons crash i18n iconthemes \
		kio kirigami2 kirigami-addons \
		ecm:build
USE_QT=		base declarative svg

OPTIONS_DEFINE=		OPTIMIZERS

OPTIMIZERS_DESC=	Install required utilities
OPTIMIZERS_RUN_DEPENDS=	jpegoptim:graphics/jpegoptim \
			oxipng:graphics/oxipng \
			cwebp:graphics/webp \
			scour:textproc/py-scour

.include <bsd.port.mk>
