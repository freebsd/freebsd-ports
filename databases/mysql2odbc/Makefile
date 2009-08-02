# New ports collection makefile for:	mysql2odbc
# Date created:				8 Aug 2005
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mysql2odbc
PORTVERSION=	0.99.2
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://www.iodbc.org/downloads/mysql2odbc/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Openlink MySQL-ODBC Gateway

OPTIONS=	UNIXODBC	"Build with unixODBC" on \
		IODBC		"Build with iODBC" off \

.include <bsd.port.pre.mk>

.if !defined(WITH_UNIXODBC) && !defined(WITH_IODBC)
WITH_UNIXODBC=	yes
.endif

.if defined(WITH_UNIXODBC) && defined(WITH_IODBC)
BROKEN=		UNIXODBC and IODBC options are mutually exclusive
.endif

.if defined(WITH_UNIXODBC)
LIB_DEPENDS=	odbc:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS=	--with-unixodbc=${LOCALBASE}
.endif

.if defined(WITH_IODBC)
LIB_DEPENDS=	iodbc:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS=	--with-iodbc
.endif

CONFIGURE_ARGS+=--libdir=${PREFIX}/mysql2odbc
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"

USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

.include <bsd.port.post.mk>
