# ex:ts=8
# Ports collection makefile for:	libdbi-drivers
# Date created:			Oct 30, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libdbi-drivers
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drivers for libdbi

LIB_DEPENDS=	dbi.0:${PORTSDIR}/databases/libdbi

USE_GNOME=	gnometarget lthack
USE_LIBTOOL_VER=	13
CONFIGURE_ARGS=	--disable-static \
		--with-dbi-incdir=${LOCALBASE}/include/dbi

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_PGSQL)
LIB_DEPENDS+=	pq.3:${PORTSDIR}/databases/postgresql7
CONFIGURE_ARGS+=	--with-pgsql
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if defined(WITH_SQLITE)
LIB_DEPENDS+=	sqlite.2:${PORTSDIR}/databases/sqlite2
CONFIGURE_ARGS+=	--with-sqlite
PLIST_SUB+=	SQLITE=""
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

#.if defined(WITH_MSQL)
#LIB_DEPENDS+=	msql.1:${PORTSDIR}/databases/msql
#CONFIGURE_ARGS+=	--with-msql
#PLIST_SUB+=	MSQL=""
#.else
#PLIST_SUB+=	MSQL="@comment "
#.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O20|$$CFLAGS|g' ${WRKSRC}/configure

.include <bsd.port.mk>
