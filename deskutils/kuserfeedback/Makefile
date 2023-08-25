PORTNAME=	kuserfeedback
DISTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	deskutils kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Framework for collecting user feedback
WWW=		https://github.com/kde/kuserfeedback

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		bison cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	ecm
USE_QT=		charts core declarative gui network printsupport svg widgets \
		buildtools:build help:build qmake:build

OPTIONS_DEFINE=	SERVER
OPTIONS_DEFINE+=		DOCS
OPTIONS_EXCLUDE_purecap=	DOCS
OPTIONS_SUB=	yes

SERVER_DESC=		Enable all features (requires php)
SERVER_USES=		php
SERVER_CMAKE_BOOL=	ENABLE_PHP
SERVER_BUILD_DEPENDS=	phpunit:devel/phpunit6@${PHP_FLAVOR}
SERVER_RUN_DEPENDS=	phpunit:devel/phpunit6@${PHP_FLAVOR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
USE_QT+=	qdoc:build
.endif

.include <bsd.port.mk>
