PORTNAME=	kontrast
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics accessibility kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Color contrast checker
WWW=		https://apps.kde.org/en/kontrast

LIB_DEPENDS=	libQCoro6Core.so:devel/qcoro \
		libfuturesql6.so:databases/futuresql

USES=		cmake compiler:c++11-lang gettext kde:6 pkgconfig qt:6 tar:xz
USE_KDE=	coreaddons crash i18n kirigami-addons kirigami2 \
		ecm:build
USE_QT=		base

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
