# ex:ts=8
# New ports collection makefile for:	dbconnect
# Date created:			Jul 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dbconnect
PORTVERSION=	0.2.4
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

.if defined(WITH_MYSQL)
LIB_DEPENDS+=	mysqlclient:${PORTSDIR}/databases/mysql323-client
CONFIGURE_ARGS+=	--with-mysql=yes \
			--with-mysqlinclude=${LOCALBASE}/include/mysql \
			--with-mysqllib=${LOCALBASE}/lib/mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_PGSQL)
LIB_DEPENDS+=	pq:${PORTSDIR}/databases/postgresql7
CONFIGURE_ARGS+=	--with-pgsql=yes \
			--with-pgsqlinclude=${LOCALBASE}/include \
			--with-pgsqllib=${LOCALBASE}/lib
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if defined(WITH_UNIXODBC)
LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-unixodbc=yes \
			--with-unixodbcinclude=${LOCALBASE}/include \
			--with-unixodbclib=${LOCALBASE}/lib
PLIST_SUB+=	UNIXODBC=""
.else
PLIST_SUB+=	UNIXODBC="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|g++|${CXX}|g ; \
		 s|@CFLAGS@|${CXXFLAGS}|g ; \
		 s|gcc|${CXX}|g ; \
		 s|cp -f \.|${INSTALL_DATA} .|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
