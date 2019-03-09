# $FreeBSD$

PORTNAME=	ark
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	3
CATEGORIES=	archivers kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Archiving tool for KDE

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang gettext libarchive kde:5 \
		qt:5 shared-mime-info tar:xz
USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons doctools ecm i18n iconthemes \
		itemmodels itemviews jobwidgets khtml kio parts pty service \
		solid sonnet textwidgets widgetsaddons xmlgui
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools_build qmake_build

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	7ZIP RAR ZIP DOCS
OPTIONS_DEFAULT=	7ZIP ZIP DOCS
OPTIONS_DEFAULT_i386=	RAR
OPTIONS_DEFAULT_amd64=	RAR
OPTIONS_SUB=		YES

# The 7ZIP and RAR options only need runtime dependencies;
# the port builds identically with or without them.
7ZIP_DESC=	Support for 7-Zip archives (runtime)
7ZIP_RUN_DEPENDS=	7z:archivers/p7zip

RAR_DESC=	Support for RAR archives (runtime)
RAR_RUN_DEPENDS=	unrar:archivers/unrar \
			rar:archivers/rar

ZIP_DESC=	Support for ZIP archives
ZIP_LIB_DEPENDS=	libzip.so:archivers/libzip
ZIP_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_LibZip

.include <bsd.port.mk>
