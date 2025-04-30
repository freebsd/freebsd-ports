PORTNAME=	ark
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	archivers kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Archiving tool for KDE
WWW=		https://utils.kde.org/projects/ark/

LICENSE=	GPLv2+

USES=		cmake compiler:c++11-lang cpe desktop-file-utils gettext gl \
		kde:6 libarchive qt:6 tar:xz xorg
USE_KDE=	bookmarks colorscheme completion config configwidgets \
		coreaddons crash dbusaddons doctools filemetadata i18n \
		iconthemes itemviews jobwidgets kio parts pty service solid \
		widgetsaddons windowsystem xmlgui \
		ecm:build
USE_GL=		gl opengl
USE_QT=		base
USE_XORG=	x11
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	7ZIP RAR ZIP DOCS
OPTIONS_DEFAULT=	7ZIP ZIP DOCS
OPTIONS_DEFAULT_amd64=	RAR
OPTIONS_SUB=		YES

# The 7ZIP and RAR options only need runtime dependencies;
# the port builds identically with or without them.
7ZIP_DESC=	Support for 7-Zip archives (runtime)
7ZIP_RUN_DEPENDS=	7zz:archivers/7-zip

RAR_DESC=	Support for RAR archives (runtime)
RAR_RUN_DEPENDS=	unrar:archivers/unrar \
			rar:archivers/rar

ZIP_DESC=	Support for ZIP archives
ZIP_LIB_DEPENDS=	libzip.so:archivers/libzip
ZIP_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_LibZip

# Override shared library version
KDE_APPLICATIONS_SHLIB_VER=	${KDE_APPLICATIONS_VERSION}

.include <bsd.port.mk>
