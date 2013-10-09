# Created by: Sevan Janiyan <venture37@geeklan.co.uk>
# $FreeBSD$

PORTNAME=	iplike
PORTVERSION=	2.0.3
CATEGORIES=	databases
MASTER_SITES=	SF/opennms/IPLIKE/stable-2.0/

MAINTAINER=	venture37@geeklan.co.uk
COMMENT=	C implementation of the OpenNMS iplike stored procedure

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PGSQL=	yes
SUB_FILES=	pkg-message

PLIST_FILES=	lib/postgresql/iplike.la \
	lib/postgresql/iplike.so \
	sbin/install_iplike.sh

.include <bsd.port.mk>
