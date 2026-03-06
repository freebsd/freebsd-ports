PORTNAME=	glaxnimate
DISTVERSION=	0.6.0
MASTER_SITES=	KDE/stable/glaxnimate/${DISTVERSION}/
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Simple vector animation program
WWW=		https://apps.kde.org/glaxnimate/

BUILD_DEPENDS=	pip:devel/py-pip@${PY_FLAVOR}
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libpotrace.so:graphics/libpotrace

USES=		cmake compiler:c++17-lang gettext-tools gl kde:6 libarchive \
		python qt:6 tar:xz
USE_GL=		gl
USE_QT=		base svg tools
USE_KDE=	archive breeze-icons colorscheme completion config configwidgets \
		coreaddons crash guiaddons i18n iconthemes widgetsaddons xmlgui \
		ecm:build

.include <bsd.port.mk>
