# Created by: Mina R Waheeb <syncer@gmail.com>
# $FreeBSD$

PORTNAME=	mysql-xql
PORTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://www.mysqludf.org/lib_mysqludf_xql/
DISTNAME=	lib_mysqludf_xql-${PORTVERSION}

MAINTAINER=	syncer@gmail.com
COMMENT=	Library provides XML output functions to MySQL server

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip
USES=		gmake libtool
USE_GNOME=	libxml2
USE_MYSQL=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	lib/mysql/plugin/lib_mysqludf_xql.so

.include <bsd.port.mk>
