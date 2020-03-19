# Created by: Markus Brueffer <brueffer@phoenix-systems.de>
# $FreeBSD$

PORTNAME=	basket
DISTVERSIONPREFIX=	v
DISTVERSION=	2.49a-46
DISTVERSIONSUFFIX=	-g60e38c6
PORTREVISION=	5
CATEGORIES=	deskutils kde

PATCH_SITES=	https://github.com/basket-notepads/basket/commit/
PATCHFILES=	094580f207b5ba9f44e9af00834f9c93f06fb440.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Desktop organization tool

LICENSE=	GPLv2

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgit2.so:devel/libgit2

USES=		cmake compiler:c++11-lang desktop-file-utils gettext-tools \
		kde:5 pkgconfig qt:5 shared-mime-info tar:bzip2 xorg
USE_KDE=	ecm archive auth codecs completion config configwidgets \
		coreaddons crash dbusaddons doctools filemetadata globalaccel \
		guiaddons i18n iconthemes jobwidgets kcmutils kio \
		notifications parts service sonnet textwidgets widgetsaddons \
		windowsystem xmlgui
USE_QT=		concurrent core dbus gui network phonon4 testlib widgets xml \
		buildtools_build qmake_build
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	basket-notepads

PLIST_SUB=	QT5_VERSION=${QT5_VERSION}

.include <bsd.port.mk>
