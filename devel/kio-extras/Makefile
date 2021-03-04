# $FreeBSD$

PORTNAME=	kio-extras
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications # kde kde-applications-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 library to increase the functionality of KIO

LIB_DEPENDS=	libtag.so:audio/taglib \
		libHalf.so:graphics/ilmbase \
		libkdsoap.so:www/kdsoap

USES=		cmake compiler:c++11-lib gettext gperf kde:5 \
		pkgconfig qt:5 shared-mime-info shebangfix tar:xz xorg
USE_KDE=	activities archive auth bookmarks codecs completion config \
		configwidgets coreaddons crash dbusaddons dnssd doctools ecm \
		emoticons guiaddons i18n iconthemes init itemmodels itemviews \
		jobwidgets js kdelibs4support khtml kio notifications parts \
		pty service solid sonnet syntaxhighlighting textwidgets unitconversion \
		widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus declarative gui location network phonon4 printsupport \
		sql svg testlib webchannel widgets xml \
		buildtools_build qmake_build
USE_XORG=	xcursor
SHEBANG_FILES=	info/kde-info2html

# CVE-2018-19120
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Qt5WebEngineWidget

OPTIONS_DEFINE=	SAMBA MTP EXR EXIV SLP SSH TAGLIB DOCS
OPTIONS_DEFAULT=SAMBA MTP EXR EXIV SLP SSH TAGLIB
OPTIONS_SUB=	yes

SAMBA_DESC=		Needed to build the SMB kioslave
SAMBA_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Samba
SAMBA_USES=		samba:lib

MTP_DESC=		Needed to build the MTP kioslave
MTP_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Mtp
MTP_LIB_DEPENDS=	libmtp.so:multimedia/libmtp

EXR_DESC=		Provides support for OpenEXR formatted images in the thumbnail kioslave
EXR_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_OpenEXR
EXR_LIB_DEPENDS=	libIlmImf.so:graphics/openexr

EXIV_DESC=		Provides support for automatic rotation of JPEGs in the thumbnail kioslave
EXIV_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Exiv2
EXIV_LIB_DEPENDS=	libexiv2.so:graphics/exiv2

SLP_DESC=		Provides SLP support in the network:/ kioslave
SLP_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_SLP
SLP_LIB_DEPENDS=	libslp.so:net/openslp

SSH_DESC=		Needed to build the SFTP kioslave
SSH_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_LibSSH
SSH_LIB_DEPENDS=	libssh.so:security/libssh

# Our taglib is too old
TAGLIB_DESC=		Needed to build the audio thumbnail kioslave
TAGLIB_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Taglib
TAGLIB_LIB_DEPENDS=	libtag.so:audio/taglib

.include <bsd.port.mk>
