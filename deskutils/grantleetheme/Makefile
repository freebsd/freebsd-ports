PORTNAME=	grantleetheme
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE PIM grantleetheme
WWW=		https://www.kde.org/

LICENSE=	LGPL21

USES=		cmake compiler:c++11-lib gettext kde:6 pkgconfig qt:6 tar:xz
USE_KDE=	attica auth codecs config configwidgets coreaddons guiaddons \
		i18n iconthemes newstuff service texttemplate widgetsaddons \
		xmlgui \
		ecm:build
USE_QT=		base
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
