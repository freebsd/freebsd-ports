PORTNAME=		sope2
PORTVERSION=		2.4.3
PORTREVISION=		2
CATEGORIES=		devel gnustep
MASTER_SITES=		http://www.sogo.nu/files/downloads/SOGo/Sources/
DISTNAME=		SOPE-${PORTVERSION}

MAINTAINER=		acm@FreeBSD.org
COMMENT=		Extensive set of GNUstep web application frameworks
WWW=		https://sogo.nu/

LICENSE=		LGPL20

LIB_DEPENDS=		libmemcached.so:databases/libmemcached

WRKSRC=			${WRKDIR}/SOPE

OPTIONS_DEFINE=		LDAP MYSQL PGSQL MEMCACHED
OPTIONS_DEFAULT=	LDAP PGSQL MEMCACHED
OPTIONS_SUB=		yes

MYSQL_DESC=		Build with MySQL support
PGSQL_DESC=		Build with PostgreSQL support
MEMCACHED_DESC=		Install memcached

USES=			gmake gnome iconv gnustep ssl
USE_GNOME=		libxml2
USE_GNUSTEP=		base build
USE_LDCONFIG=		${GNUSTEP_LOCAL_LIBRARIES}
LLD_UNSAFE=		yes # PR 230608

SUB_LIST+=		GNUSTEP_LOCAL_TOOLS=${GNUSTEP_LOCAL_TOOLS} \
			GNUSTEP_MAKEFILES=${GNUSTEP_MAKEFILES}

CONFIGURE_ARGS=		--with-gnustep --disable-debug --enable-strip

LDAP_USES=		ldap
PGSQL_USES=		pgsql
MYSQL_USES=		mysql
MEMCACHED_RUN_DEPENDS=	${LOCALBASE}/bin/memcached:databases/memcached

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
ADDITIONAL_CPPFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/sope-core/NGStreams/configure
.for f in config.guess config.sub
	@${CP} ${TEMPLATES}/$f ${WRKSRC}/sope-core/NGStreams/
.endfor

post-patch-LDAP-off:
	@${REINPLACE_CMD} -e '/checkLinking "ldap"/d' ${WRKSRC}/configure

post-patch-PGSQL-off:
	@${REINPLACE_CMD} -e '/checkLinking "pq"/d' ${WRKSRC}/configure

post-patch-MYSQL-off:
	@${REINPLACE_CMD} -e '/checkLinking "mysqlclient"/d' ${WRKSRC}/configure

do-configure:
	cd ${WRKSRC} ; . ${GNUSTEP_MAKEFILES}/GNUstep.sh ; ./configure ${CONFIGURE_ARGS}

.include <bsd.port.mk>
