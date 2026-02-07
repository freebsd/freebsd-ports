PORTNAME=	kpipewire
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	audio kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Components relating to Flatpak 'pipewire' use in Plasma

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libdrm.so:graphics/libdrm \
		libepoxy.so:graphics/libepoxy \
		libpipewire-0.3.so:multimedia/pipewire \
		libva.so:multimedia/libva \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake gettext gl kde:6 pkgconfig qt:6 tar:xz
USE_GL=		egl gbm gl opengl
USE_KDE=	coreaddons i18n \
		ecm:build plasma-wayland-protocols:build
USE_QT=		base declarative wayland

.include <bsd.port.mk>
