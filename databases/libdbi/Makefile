# ex:ts=8
# New ports collection makefile for:	libdbi
# Date created:			Nov 4, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libdbi
PORTVERSION=	0.6.2
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://linux.ucla.edu/~dap24/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
PLIST_SUB=	VERSION=${PORTVERSION}

.if defined(WITH_PGSQL)
LIB_DEPENDS+=	pq:${PORTSDIR}/databases/postgresql7
CONFIGURE_ARGS+=	--with-pgsql
PLIST_SUB+=	WITH_PQ=""
.else
PLIST_SUB+=	WITH_PQ="@comment "
.endif

.if defined(WITH_MYSQL)
LIB_DEPENDS+=	mysqlclient:${PORTSDIR}/databases/mysql323-client
CONFIGURE_ARGS+=	\
		--with-mysql \
		--with-mysql-incdir=${LOCALBASE}/include \
		--with-mysql-libdir=${LOCALBASE}/lib/mysql
PLIST_SUB+=	WITH_MY=""
.else
PLIST_SUB+=	WITH_MY="@comment "
.endif

.include <bsd.port.mk>
