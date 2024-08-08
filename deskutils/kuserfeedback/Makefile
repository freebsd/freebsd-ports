PORTNAME=	kuserfeedback
DISTVERSION=	1.3.0
CATEGORIES=	deskutils kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Framework for collecting user feedback
WWW=		https://github.com/kde/kuserfeedback

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		bison cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	ecm:build
USE_QT=		charts core declarative gui linguisttools network printsupport \
		svg widgets \
		buildtools:build help:build qdoc:build qmake:build

OPTIONS_DEFINE=	SERVER

SERVER_DESC=		Enable all features (requires php)
SERVER_USES=		php
SERVER_CMAKE_BOOL=	ENABLE_PHP ENABLE_PHP_UNIT
SERVER_BUILD_DEPENDS=	phpunit:devel/phpunit9@${PHP_FLAVOR}
SERVER_RUN_DEPENDS=	phpunit:devel/phpunit9@${PHP_FLAVOR}

.include <bsd.port.mk>
