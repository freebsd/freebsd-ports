# Created by: gahr
# $FreeBSD$

PORTNAME=	mysql-connector-c++
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	Connector-C++

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A MySQL database connector for C++

LICENSE=	GPLv2

LIB_DEPENDS=	boost_regex:${PORTSDIR}/devel/boost-libs

USE_MYSQL=	51+
USE_LDCONFIG=	yes
USE_CMAKE=	yes
CMAKE_OUTSOURCE=yes

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
