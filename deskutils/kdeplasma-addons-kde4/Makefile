# $FreeBSD$

PORTNAME=	kdeplasma-addons
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	7
CATEGORIES=	deskutils kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Extra plasmoids for KDE SC 4

LIB_DEPENDS=	libqalculate.so:math/libqalculate \
		libqwt.so:x11-toolkits/qwt5 \
		libqca.so:devel/qca \
		libqoauth.so:net/qoauth \
		libqjson.so:devel/qjson
CONFLICTS_INSTALL=	plasma-applet-icontasks-0.[89].*

USES=		cmake:outsource eigen:2 kde:4 pkgconfig shared-mime-info tar:xz
USE_KDE=	kdelibs libkexiv2 pimlibs workspace \
		akonadi attica automoc4 qimageblitz soprano
USE_QT4=	corelib dbus declarative gui network script sql webkit \
		qmake_build moc_build rcc_build uic_build
USE_XORG=	x11 xrender xtst
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	MARBLE SCIM IBUS
OPTIONS_DEFAULT=	MARBLE
OPTIONS_SUB=	yes

MARBLE_DESC=	Support for desktop globe wallpaper
MARBLE_USE=	KDE=marble
MARBLE_CMAKE_OFF=	-DWITH_Marble=off

IBUS_DESC=	Enable IBUS backend for input dialog
IBUS_LIB_DEPENDS=	libibus-1.0.so:textproc/ibus
IBUS_CMAKE_OFF=	-DBUILD_ibus=off

SCIM_DESC=	Enable SCIM backend for input dialog
SCIM_LIB_DEPENDS=	libscim-1.0.so:textproc/scim
SCIM_CMAKE_OFF=	-DBUILD_scim=off

post-patch:
# Respect prefix, don't update MIME when installing.
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d; /SharedMimeInfo/ d' \
		${WRKSRC}/applets/lancelot/parts/CMakeLists.txt

.include <bsd.port.mk>
