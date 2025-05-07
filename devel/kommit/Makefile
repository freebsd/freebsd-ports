PORTNAME=	kommit
DISTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Git GUI client for KDE
WWW=		https://apps.kde.org/kommit/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libdolphinvcs.so:x11-fm/dolphin

USES=		cmake compiler:c++17-lang gettext kde:6 localbase:ldflags \
		pkgconfig qt:6 tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons doctools i18n itemviews jobwidgets \
		kio parts service solid sonnet syntaxhighlighting texteditor \
		textwidgets widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11

.include <bsd.port.mk>
