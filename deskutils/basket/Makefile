# Created by: Markus Brueffer <brueffer@phoenix-systems.de>
# $FreeBSD$

PORTNAME=	basket
DISTVERSIONPREFIX=	v
DISTVERSION=	2.49a-46
DISTVERSIONSUFFIX=	-g60e38c6
CATEGORIES=	deskutils kde

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Desktop organization tool

LICENSE=	GPLv2

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgit2.so:devel/libgit2

USES=		cmake desktop-file-utils gettext-tools kde:5 pkgconfig qt:5 \
		shared-mime-info tar:bzip2
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

.include <bsd.port.mk>
