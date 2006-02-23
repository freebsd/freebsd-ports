# New ports collection makefile for:	powerdns
# Date Created:				14.Jan 2003
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	powerdns
PORTVERSION=	2.9.19
PORTREVISION=	2
CATEGORIES=	dns ipv6
MASTER_SITES=	http://downloads.powerdns.com/releases/ \
		http://mirrors.evolva.ro/powerdns.com/releases/
DISTNAME=	pdns-${PORTVERSION}

MAINTAINER=	tremere@cainites.net
COMMENT=	An advanced DNS server with SQL backend

BUILD_DEPENDS=	bjam:${PORTSDIR}/devel/boost

USE_GMAKE=	YES
USE_SUBMAKE=	YES
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	YES
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-modules="${CONFIGURE_MODULES} pipe" \
			--with-dynmodules=""
#			--enable-debug
SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		CURDIR2="${.CURDIR}" \
		MKDIR="${MKDIR}" \
		DISTNAME="${DISTNAME}" \
		POWERDNS_OPTIONS="${POWERDNS_OPTIONS}"
MAN8=		pdns_control.8 pdns_server.8 zone2sql.8

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

USE_RC_SUBR+=	pdns

# use user config if possible
.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.else
.if defined(BATCH)
# default package, can be configured in /etc/make.conf
POWERDNS_OPTIONS?=	\"PostgreSQL\"
.endif
# make INDEX match
NO_DESCRIBE=yes
.endif

.if defined(WITH_POSTGRESQL_DRIVER) && !defined(WITHOUT_POSTGRESQL_DRIVER)
LIB_DEPENDS+=	pq[+][+].4:${PORTSDIR}/databases/postgresql-libpq++
CONFIGURE_ARGS+=	--enable-pgsql --with-pgsql-includes=${LOCALBASE}/include
CONFIGURE_MODULES+=	"gpgsql"
CFLAGS+=		-DDLLIMPORT=""
.else
CONFIGURE_ARGS+=	--disable-pgsql
.endif

.if defined(WITH_MYSQL_DRIVER)
USE_MYSQL?=		YES
CONFIGURE_ARGS+=	--enable-mysql --with-mysql-includes=${LOCALBASE}
CONFIGURE_MODULES+=	"gmysql"
PLIST_SUB+=		WITHMYSQL=""
.else
CONFIGURE_ARGS+=	--disable-mysql
PLIST_SUB+=		WITHMYSQL="@comment "
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP?=		YES
CONFIGURE_MODULES+=	"ldap"
PLIST_SUB+=		WITHLDAP=""
CXXFLAGS+=		-L${LOCALBASE}/lib
.else
PLIST_SUB+=		WITHLDAP="@comment "
.endif

.if defined(WITH_SQLITE)
LIB_DEPENDS+=	sqlite.2:${PORTSDIR}/databases/sqlite2
CONFIGURE_ARGS+=	--enable-sqlite
CONFIGURE_MODULES+=	"gsqlite"
PLIST_SUB+=		WITHSQLLITE=""
.else
CONFIGURE_ARGS+=	--disable-sqlite
PLIST_SUB+=		WITHSQLLITE="@comment "
.endif

.if defined(POWERDNS_WITH_RECURSOR)
USE_RC_SUBR+=	pdns_recursor
CONFIGURE_ARGS+=	--enable-recursor
PLIST_SUB+=		RECURSOR=""
.else
PLIST_SUB+=		RECURSOR="@comment "
.endif

.if defined(POWERDNS_WITH_RECURSOR)
.if exists(/usr/include/ucontext.h) && ${OSVERSION} >= 500000
UCONTEXT!=	${AWK} '/setcontext/ { print "YES" }' \
		/usr/include/ucontext.h
.if ${UCONTEXT} == ""
BROKEN=		setcontext for recursor not found or FreeBSD version lower than 5.0
.endif
.endif
.endif

.if ${OSVERSION} < 500039
USE_GCC=3.4
.endif

.if defined(NO_DESCRIBE)
describe:
.if defined(BATCH)
	@ ${SETENV} ${SCRIPTS_ENV} ${SH} ${FILESDIR}/configure.powerdns
.endif
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} BATCH=yes ${.TARGET}
.endif

pre-everything::
	@ ${SETENV} ${SCRIPTS_ENV} ${SH} ${FILESDIR}/configure.powerdns

post-clean:
	@ ${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if defined(WITH_LDAP)
post-patch:
	${REINPLACE_CMD} -e 's;-I. ;-I. -I${LOCALBASE}/include ;' \
		-e 's;la_LDFLAGS =;la_LDFLAGS = -L${LOCALBASE}/lib;' \
		${WRKSRC}/modules/ldapbackend/Makefile.in
	${REINPLACE_CMD} -e 's;@LIBDL@;@LIBDL@ -L${LOCALBASE}/lib;' \
		-e 's;@modulelibs@;@modulelibs@ -llber;' \
		${WRKSRC}/pdns/Makefile.in
.endif

post-install:
.if !exists(${PREFIX}/etc/pdns.conf)
	${INSTALL_DATA} ${PREFIX}/etc/pdns.conf-dist ${PREFIX}/etc/pdns.conf
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
.for i in pdns.conf pdns_mysql.sql pdns_postgresql.sql pdns_sqlite.sql
	${INSTALL_DATA} ${FILESDIR}/$i ${EXAMPLESDIR}/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
