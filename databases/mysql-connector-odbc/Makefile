# New ports collection makefile for:	MyODBC
# Date created:				24 Oct 2000
# Whom:					ebakke@trolltech.com
#
# $FreeBSD$
#

PORTNAME=	MyODBC
PORTVERSION=	2.50.34
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.sunet.se/pub/unix/databases/relational/mysql/Downloads/MyODBC/

MAINTAINER=	ebakke@trolltech.com

LIB_DEPENDS=	iodbc.2:${PORTSDIR}/databases/libiodbc \
		mysqlclient.10:${PORTSDIR}/databases/mysql323-client

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-mysql-libs=${PREFIX}/lib/mysql \
		--with-mysql-includes=${PREFIX}/include/mysql
USE_GMAKE=	yes

.include <bsd.port.mk>
