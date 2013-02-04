# Created by: gahr
# $FreeBSD$

PORTNAME=	mysql-connector-c
PORTVERSION=	6.0.2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	Connector-C

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	MySQL database connector for C

LICENSE=	GPLv2

USE_MYSQL=	51+
USE_CMAKE=	yes
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
