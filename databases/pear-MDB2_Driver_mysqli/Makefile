# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MDB2_Driver_mysqli
DISTVERSION=	1.5.0b4
CATEGORIES=	databases www pear

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	PEAR MySQL MDB2 driver

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PEAR_PKGNAMEPREFIX}MDB2>=0:databases/pear-MDB2@${PHP_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		pear php
USE_PHP=	mysqli

.include <bsd.port.mk>
