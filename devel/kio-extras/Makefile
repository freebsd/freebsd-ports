PORTNAME=	kio-extras
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma6 library to increase the functionality of KIO
WWW=		https://projects.kde.org/projects/kde/workspace/kio-extras

LIB_DEPENDS=	libtag.so:audio/taglib \
		libImath.so:math/Imath \
		libkdsoap-qt6.so:www/kdsoap \
		libKDSoapWSDiscoveryClient.so:www/kdsoap-ws-discovery-client\
		libQCoro6Core.so:devel/qcoro

USES=		cmake compiler:c++11-lib gettext gperf kde:6 pkgconfig qt:6 \
		shared-mime-info shebangfix tar:xz xorg
USE_KDE=	activities activities-stats archive auth bookmarks codecs \
		completion config configwidgets coreaddons crash dbusaddons \
		dnssd doctools guiaddons i18n iconthemes itemmodels itemviews \
		jobwidgets kcmutils kio notifications parts phonon pty service \
		solid sonnet syntaxhighlighting textwidgets unitconversion \
		widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base declarative
USE_XORG=	x11 xcursor
SHEBANG_FILES=	info/kde-info2html

# CVE-2018-19120
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Qt6WebEngineWidget

OPTIONS_DEFINE=	SAMBA AFC MTP EXIV OPENEXR SLP SSH TAGLIB DOCS
OPTIONS_DEFAULT=	SAMBA AFC MTP EXIV OPENEXR SLP SSH TAGLIB
OPTIONS_SUB=	yes

SAMBA_DESC=		Needed to build the SMB kioslave
SAMBA_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Samba
SAMBA_USES=		samba:lib

AFC_DESC=		Needed to build AFC (Apple File Conduit) kioslave
AFC_LIB_DEPENDS=	libimobiledevice-1.0.so:comms/libimobiledevice \
			libplist-2.0.so:devel/libplist
AFC_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_IMobileDevice \
			CMAKE_DISABLE_FIND_PACKAGE_PList

MTP_DESC=		Needed to build the MTP kioslave
MTP_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Mtp
MTP_LIB_DEPENDS=	libmtp.so:multimedia/libmtp

EXIV_DESC=		Provides support for automatic rotation of JPEGs in the thumbnail kioslave
EXIV_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_KF6kExiv2
EXIV_USE=		KDE=libkexiv2

OPENEXR_DESC=		Provides support for OpenEXR formatted images in the thumbnail kioslave
OPENEXR_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_OpenEXR
OPENEXR_LIB_DEPENDS=	libOpenEXR.so:graphics/openexr

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
