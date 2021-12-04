PORTNAME=	ktexteditor
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 advanced embeddable text editor

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libeditorconfig.so:editors/editorconfig-core-c

USES=		cmake compiler:c++11-lib gettext kde:5 cpe pkgconfig qt:5 tar:xz
USE_KDE=	archive auth codecs completion config configwidgets \
		coreaddons guiaddons i18n iconthemes itemviews \
		jobwidgets kio parts service sonnet syntaxhighlighting \
		textwidgets widgetsaddons windowsystem xmlgui \
		ecm_build
USE_QT=		concurrent core dbus declarative gui network printsupport \
		script widgets xml xmlpatterns \
		buildtools_build qmake_build

.include <bsd.port.mk>
