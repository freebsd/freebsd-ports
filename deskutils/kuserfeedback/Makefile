PORTNAME=	kuserfeedback
DISTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	deskutils kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

PATCH_SITES=	https://invent.kde.org/libraries/kuserfeedback/-/commit/
PATCHFILES=	17db7d75643b4f3dccd5b36a6ab175f03ba74297.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Framework for collecting user feedback

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	phpunit:devel/phpunit6@${PHP_FLAVOR}
RUN_DEPENDS=	phpunit:devel/phpunit6@${PHP_FLAVOR}

USES=		bison cmake compiler:c++11-lang kde:5 php qt:5 tar:xz
USE_KDE=	ecm
USE_QT=		charts core declarative gui network printsupport svg widgets \
		buildtools_build help_build qdoc_build qmake_build

.include <bsd.port.mk>
