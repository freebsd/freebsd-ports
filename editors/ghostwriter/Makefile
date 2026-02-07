PORTNAME=	ghostwriter
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	editors kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Distraction-free Markdown editor
WWW=		https://ghostwriter.kde.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++20-lang desktop-file-utils \
		kde:6 qt:6 tar:xz
USE_KDE=	configwidgets coreaddons sonnet widgetsaddons xmlgui \
		doctools:build ecm:build
USE_QT=		base svg webchannel webengine \
		tools:build
# cf. PR 224488
LDFLAGS+=	-Wl,--as-needed

.include <bsd.port.mk>
