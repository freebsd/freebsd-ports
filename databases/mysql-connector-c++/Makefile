# New ports collection Makefile for:	mysql-connector-c++
# Date created:				25 August 2011
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	mysql-connector-c++
PORTVERSION=	1.1.1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	Connector-C++

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A MySQL database connector for C++

LICENSE=	GPLv2

LIB_DEPENDS=	boost_regex.4:${PORTSDIR}/devel/boost-libs

USE_MYSQL=	51+
USE_LDCONFIG=	yes
USE_CMAKE=	yes
CMAKE_OUTSOURCE=yes

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
