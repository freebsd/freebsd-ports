# Created by: gahr
# $FreeBSD$

PORTNAME=	mysql-connector-c
PORTVERSION=	6.1.3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	Connector-C
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	MySQL database connector for C

LICENSE=	GPLv2

USE_MYSQL=	51+
USES=		cmake:outsource
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
