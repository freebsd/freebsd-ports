# New ports collection makefile for:	powerdns
# Date Created:				14.Jan 2003
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	powerdns
PORTVERSION=	2.9.10
CATEGORIES=	net ipv6
MASTER_SITES=	http://downloads.powerdns.com/releases/
DISTNAME=	pdns-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An advanced DNS server with SQL backend

USE_GMAKE=	YES
USE_SUBMAKE=	YES
USE_REINPLACE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-modules="${CONFIGURE_MODULES} pipe" \
			--with-dynmodules=""
#			--enable-debug

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
LIB_DEPENDS=	pq[+][+].4:${PORTSDIR}/databases/postgresql-libpq++
CONFIGURE_ARGS+=	--enable-pgsql
CONFIGURE_MODULES+=	"gpgsql"
.else
CONFIGURE_ARGS+=	--disable-pgsql
.endif

.if defined(WITH_MYSQL_DRIVER)
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
CONFIGURE_ARGS+=	--enable-mysql
CONFIGURE_MODULES+=	"gmysql"
.else
CONFIGURE_ARGS+=	--disable-mysql
.endif

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		CURDIR2="${.CURDIR}" \
		MKDIR="${MKDIR}" \
		DISTNAME="${DISTNAME}" \
		POWERDNS_OPTIONS="${POWERDNS_OPTIONS}"

MAN8=		pdns_control.8 pdns_server.8 zone2sql.8

pre-everything::
	@ ${SETENV} ${SCRIPTS_ENV} ${SH} ${FILESDIR}/configure.powerdns

post-install:
.if !exists(${PREFIX}/etc/pdns.conf)
	${INSTALL_DATA} ${PREFIX}/etc/pdns.conf-dist ${PREFIX}/etc/pdns.conf
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
.for i in pdns.conf pdns_mysql.sql pdns_postgresql.sql
	${INSTALL_DATA} ${FILESDIR}/$i ${EXAMPLESDIR}/
.endfor
.endif

post-clean:
	@ ${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if defined(NO_DESCRIBE)
describe:
.if defined(BATCH)
	@ ${SETENV} ${SCRIPTS_ENV} ${SH} ${FILESDIR}/configure.powerdns
.endif
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} BATCH=yes ${.TARGET}
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500043 && defined(WITH_LDAP)
LIB_DEPENDS+=	ldap.2:${PORTSDIR}/net/openldap20
LIB_DEPENDS+=	lber.2:${PORTSDIR}/net/openldap20
CONFIGURE_MODULES+=	"ldap"

post-patch:
	${REINPLACE_CMD} -e 's;-I. ;-I. -I${LOCALBASE}/include ;' \
		-e 's;la_LDFLAGS =;la_LDFLAGS = -L${LOCALBASE}/lib;' \
		${WRKSRC}/modules/ldapbackend/Makefile.in
	${REINPLACE_CMD} -e 's;@LIBDL@;@LIBDL@ -L${LOCALBASE}/lib;' \
		-e 's;@modulelibs@;@modulelibs@ -llber;' \
		${WRKSRC}/pdns/Makefile.in
.endif

.if ${OSVERSION} >= 500000 && defined(POWERDNS_WITH_RECURSOR)
CONFIGURE_ARGS+=	--enable-recursor
PLIST_SUB+=		RECURSOR=""
.else
PLIST_SUB+=		RECURSOR="@comment "
.endif

.include <bsd.port.post.mk>
