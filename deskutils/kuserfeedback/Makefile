# $FreeBSD$

PORTNAME=	kuserfeedback
DISTVERSION=	1.0.0
CATEGORIES=	deskutils kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Framework for collecting user feedback

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	phpunit:devel/phpunit6@${PHP_FLAVOR}
RUN_DEPENDS=	phpunit:devel/phpunit6@${PHP_FLAVOR}

USES=		bison cmake kde:5 php qt:5 tar:xz
USE_KDE=	ecm
USE_QT=		charts core declarative gui network printsupport svg widgets \
		buildtools_build help_build qdoc_build qmake_build

.include <bsd.port.mk>
