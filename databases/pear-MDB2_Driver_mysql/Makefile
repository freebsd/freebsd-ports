# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MDB2_Driver_mysql
DISTVERSION=	1.5.0b4
CATEGORIES=	databases www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR MySQL MDB2 driver

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	pear-MDB2>=0:${PORTSDIR}/databases/pear-MDB2
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		pear
USE_PHP=	mysql

.include <bsd.port.mk>
