# Created by: Euan Thoms <euan@potensol.com>
# $FreeBSD$

PORTNAME=		sope2
PORTVERSION=		2.3.18
CATEGORIES=		devel gnustep
MASTER_SITES=		http://www.sogo.nu/files/downloads/SOGo/Sources/
DISTNAME=		SOPE-${PORTVERSION}

MAINTAINER=		euan@potensol.com
COMMENT=		Extensive set of GNUstep web application frameworks

LICENSE=		LGPL20

LIB_DEPENDS=		libxml2.so:textproc/libxml2 \
			libmemcached.so:databases/libmemcached

WRKSRC=			${WRKDIR}/SOPE

OPTIONS_DEFINE=		LDAP MYSQL PGSQL MEMCACHED
OPTIONS_DEFAULT=	LDAP PGSQL MEMCACHED
OPTIONS_SUB=		yes

LDAP_DESC=		Build with LDAP support
MYSQL_DESC=		Build with MySQL support
PGSQL_DESC=		Build with PostgreSQL support
MEMCACHED_DESC=		Install memcached

USES=			gmake iconv gnustep
USE_GNUSTEP=		base build
USE_LDCONFIG=		${GNUSTEP_LOCAL_LIBRARIES}

SUB_LIST+=		GNUSTEP_LOCAL_TOOLS=${GNUSTEP_LOCAL_TOOLS} \
			GNUSTEP_MAKEFILES=${GNUSTEP_MAKEFILES}

CONFIGURE_ARGS=		--with-gnustep --disable-debug --enable-strip

LDAP_USE=		OPENLDAP=client
PGSQL_USES=		pgsql
MYSQL_USE=		MYSQL=client
MEMCACHED_RUN_DEPENDS=	${LOCALBASE}/bin/memcached:databases/memcached

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/configure

post-patch-LDAP-off:
	@${REINPLACE_CMD} -e '/checkLinking "ldap"/d' ${WRKSRC}/configure

post-patch-PGSQL-off:
	@${REINPLACE_CMD} -e '/checkLinking "pq"/d' ${WRKSRC}/configure

post-patch-MYSQL-off:
	@${REINPLACE_CMD} -e '/checkLinking "mysqlclient"/d' ${WRKSRC}/configure

do-configure:
	cd ${WRKSRC} ; . ${GNUSTEP_MAKEFILES}/GNUstep.sh ; ./configure ${CONFIGURE_ARGS}

.include <bsd.port.mk>
