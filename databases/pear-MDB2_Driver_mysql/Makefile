# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MDB2_Driver_mysql
DISTVERSION=	1.5.0b4
CATEGORIES=	databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR MySQL MDB2 driver

BROKEN=		unfetchable

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PEAR_PKGNAMEPREFIX}MDB2>=0:databases/pear-MDB2@${PHP_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		pear php
USE_PHP=	mysqli

NO_ARCH=	yes

.include <bsd.port.mk>
