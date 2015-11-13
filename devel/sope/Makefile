# Created by: Euan Thoms <euan@potensol.com>
# $FreeBSD$

PORTNAME=		sope
PORTVERSION=		2.3.2
PORTREVISION=		1
CATEGORIES=		devel gnustep
MASTER_SITES=		http://www.sogo.nu/files/downloads/SOGo/Sources/
DISTNAME=		SOPE-${PORTVERSION}

MAINTAINER=		euan@potensol.com
COMMENT=		Extensive set of GNUstep web application frameworks

LICENSE=		LGPL20

LIB_DEPENDS=		libxml2.so:${PORTSDIR}/textproc/libxml2 \
			libmemcached.so:${PORTSDIR}/databases/libmemcached

WRKSRC=			${WRKDIR}/SOPE

OPTIONS_DEFINE=		LDAP MYSQL PGSQL MEMCACHED
OPTIONS_DEFAULT=	LDAP PGSQL MEMCACHED
OPTIONS_SUB=		yes

LDAP_DESC=		Build with LDAP support
MYSQL_DESC=		Build with MySQL support
PGSQL_DESC=		Build with PostgreSQL support
MEMCACHED_DESC=		Install memcached

USES=			gmake gnustep
USE_GNUSTEP=		base build
USE_LDCONFIG=		${GNUSTEP_LOCAL_LIBRARIES}

SUB_LIST+=		GNUSTEP_LOCAL_TOOLS=${GNUSTEP_LOCAL_TOOLS} \
			GNUSTEP_MAKEFILES=${GNUSTEP_MAKEFILES}

CONFIGURE_ARGS=		--with-gnustep --disable-debug --enable-strip

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	client
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	client
.endif

.if ${PORT_OPTIONS:MMEMCACHED}
RUN_DEPENDS+=	${LOCALBASE}/bin/memcached:${PORTSDIR}/databases/memcached
.endif

post-patch:
.if ! ${PORT_OPTIONS:MLDAP}
	@${REINPLACE_CMD} -e '/checkLinking "ldap"/d' ${WRKSRC}/configure
.endif
.if ! ${PORT_OPTIONS:MPGSQL}
	@${REINPLACE_CMD} -e '/checkLinking "pq"/d' ${WRKSRC}/configure
.endif
.if ! ${PORT_OPTIONS:MMYSQL}
	@${REINPLACE_CMD} -e '/checkLinking "mysqlclient"/d' ${WRKSRC}/configure
.endif

do-configure:
	cd ${WRKSRC} ; . ${GNUSTEP_MAKEFILES}/GNUstep.sh ; ./configure ${CONFIGURE_ARGS}

.include <bsd.port.mk>
