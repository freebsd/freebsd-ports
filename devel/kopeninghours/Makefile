PORTNAME=	kopeninghours
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for parsing and evaluating OSM opening hours expressions
WWW=		https://www.kde.org/

LICENSE=	LGPL21

USES=		bison cmake compiler:c++11-lib gettext kde:6 qt:6 tar:xz
USE_KDE=	holidays i18n \
		ecm:build
USE_QT=		base declarative
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

PLIST_SUB=	SHLIB_VER=${KDE_APPLICATIONS_VERSION:R:S/0//}.${KDE_APPLICATIONS_VERSION:E}

.include <bsd.port.mk>
