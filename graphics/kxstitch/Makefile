PORTNAME=	kxstitch
DISTVERSION=	3.0.0
PORTREVISION=	2
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cross stitch pattern editor
WWW=		https://apps.kde.org/kxstitch/

USES=		cmake desktop-file-utils gettext-tools gl magick \
		kde:6 pkgconfig qt:6 shared-mime-info tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	completion config configwidgets guiaddons i18n kio \
		textwidgets widgetsaddons xmlgui \
		doctools:build ecm:build
USE_QT=		base \
		declarative:build
USE_XORG=	ice sm x11 xext

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Doxygen

.include <bsd.port.mk>
