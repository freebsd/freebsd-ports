# New ports collection makefile for:	MyODBC
# Date created:				24 Mar 2000
# Whom:					erikhb@bgnett.no
#
# $FreeBSD$
#

PORTNAME=	MyODBC
PORTVERSION=	2.50.28
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.sunet.se/pub/unix/databases/relational/mysql/Downloads/MyODBC/

MAINTAINER=	erikhb@bgnett.no

LIB_DEPENDS=	iodbc.2:${PORTSDIR}/databases/libiodbc \
		mysqlclient.6:${PORTSDIR}/databases/mysql322-client

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-mysql-libs=${PREFIX}/lib/mysql \
		--with-mysql-includes=${PREFIX}/include/mysql
USE_GMAKE=	yes

.include <bsd.port.mk>
