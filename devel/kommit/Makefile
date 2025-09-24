PORTNAME=	kommit
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.1
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

PATCH_SITES=	https://invent.kde.org/sdk/kommit/-/commit/
PATCHFILES+=	3f3af7de3a918bc83e7523e50aa6b27711d5bd24.patch:-p1 # Fix build with libgit2 <= 1.9.0

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Git GUI client for KDE
WWW=		https://apps.kde.org/kommit/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libdolphinvcs.so:x11-fm/dolphin

USES=		cmake compiler:c++17-lang gettext-tools gl kde:6 pkgconfig \
		qt:6 ssl tar:xz
USE_GL=		opengl
USE_KDE=	bookmarks colorscheme completion config configwidgets \
		coreaddons crash dbusaddons doctools guiaddons i18n itemviews \
		jobwidgets kio parts service solid sonnet syntaxhighlighting \
		texteditor textwidgets widgetsaddons xmlgui \
		ecm:build
USE_LDCONFIG=	yes
USE_QT=		base charts

.include <bsd.port.mk>
