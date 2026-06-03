PORTNAME=	kooka
DISTVERSION=	6.90.0
PORTEPOCH=	1
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Intuitive, easy to use open source scan program
WWW=		https://userbase.kde.org/Kooka

LICENSE=	GPLv2+

LIB_DEPENDS=	libpaper.so:print/libpaper \
		libsane.so:graphics/sane-backends \
		libtiff.so:graphics/tiff

USES=		cmake gettext-tools kde:6 pkgconfig qt:6 xorg
USE_KDE=	configwidgets coreaddons crash i18n \
		iconthemes kio purpose service sonnet \
		textwidgets widgetsaddons xmlgui \
		doctools:build ecm:build
USE_QT=		base
USE_XORG=	x11
USE_LDCONFIG=	yes

KDE_INVENT=	ef10c8cff98c7ad8b2f81b85cd0968bcfb0dd5af

PLIST_SUB=	SHLIB_VER=${PORTVERSION}

post-patch:
	${REINPLACE_CMD} 's,"VERSION","${PORTVERSION} GIT ef10c8cff9",' \
		${WRKSRC}/app/main.cpp

.include <bsd.port.mk>
