PORTNAME=	kommit
DISTVERSION=	1.0.2
MASTER_SITES=	KDE/stable/${PORTNAME}/
CATEGORIES=	devel kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Git gui client for KDE
WWW=		https://github.com/HamedMasafi/GitKlient

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake kde:5 localbase:ldflags pkgconfig qt:5 xorg tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons doctools ecm i18n itemviews \
		jobwidgets kio parts service solid sonnet syntaxhighlighting \
		texteditor textwidgets widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus gui network testlib widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
