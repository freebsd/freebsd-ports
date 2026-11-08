PORTNAME=	kxstitch
DISTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cross stitch pattern editor
WWW=		https://apps.kde.org/kxstitch/

USES=		cmake compiler:c++11-lang desktop-file-utils gettext \
		magick kde:6 pkgconfig qt:6 tar:xz xorg
USE_KDE=	config configwidgets completion guiaddons i18n \
		kio textwidgets widgetsaddons xmlgui \
		doctools:build ecm:build
USE_QT=		base
USE_XORG=	ice sm x11 xext

KDE_INVENT=	01e6126df91d909eead373e39ef56614ad885285

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Doxygen

.include <bsd.port.mk>
