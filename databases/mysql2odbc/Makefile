# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mysql2odbc
PORTVERSION=	0.99.2
PORTREVISION=	5
CATEGORIES=	databases
MASTER_SITES=	http://www.iodbc.org/downloads/mysql2odbc/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Openlink MySQL-ODBC Gateway

BROKEN=		unfetchable

LIB_DEPENDS=	libodbc.so:databases/unixODBC
CONFIGURE_ARGS=	--with-unixodbc=${LOCALBASE}

USES=		libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--libdir=${PREFIX}/mysql2odbc
LDFLAGS+=	-lpthread
INSTALL_TARGET=	install-strip

USE_LDCONFIG=	yes

.include <bsd.port.mk>
