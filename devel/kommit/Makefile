PORTNAME=	kommit
DISTVERSION=	1.3.1-20
CATEGORIES=	devel kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Git GUI client for KDE
WWW=		https://apps.kde.org/kommit/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libdolphinvcs.so:x11-fm/dolphin

USES=		cmake compiler:c++17-lang kde:5 localbase:ldflags \
		pkgconfig qt:5 xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons doctools i18n itemviews jobwidgets \
		kio parts service solid sonnet syntaxhighlighting texteditor \
		textwidgets widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11

KDE_INVENT=	fdfe7a23d95413007bbd6e26182dc423b2d6efa0 sdk

.include <bsd.port.mk>
