# New ports collection makefile for:	PostgreSQL
# Date created:		November 13, 1998
# Whom:			Marc G. Fournier <scrappy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	postgresql
PORTVERSION?=	7.3.1
PKGNAMESUFFIX=	-devel
CATEGORIES?=	databases
MASTER_SITES=	ftp://ftp9.us.postgresql.org/pub/mirrors/postgresql/%SUBDIR%/ \
		ftp://ftp5.us.postgresql.org/pub/PostgreSQL/%SUBDIR%/ \
		ftp://ftp3.us.postgresql.org/pub/postgresql/%SUBDIR%/ \
		ftp://ftp13.us.postgresql.org/mirror/postresql/%SUBDIR%/ \
		ftp://ftp8.us.postgresql.org/pub/pgsql/%SUBDIR%/ \
		ftp://ftp10.us.postgresql.org/pub/postgresql/%SUBDIR%/ \
		ftp://ftp.se.postgresql.org/pub/database/relational/postgresql/%SUBDIR%/ \
		ftp://ftp2.ch.postgresql.org/mirror/postgresql/%SUBDIR%/ \
		ftp://ftp.de.postgresql.org/mirror/postgresql/%SUBDIR%/ \
		ftp://ftp.chg.ru/pub/databases/postgresql/%SUBDIR%/ \
		ftp://ftp.sunet.se/pub/unix/databases/relational/postgresql/%SUBDIR%/ \
		ftp://ftp.jaist.ac.jp/pub/dbms/PostgreSQL/%SUBDIR%/ \
		ftp://ftp.us.postgresql.org/%SUBDIR%/ \
		ftp://ftp.postgresql.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	source/v${PORTVERSION}
DISTFILES=	postgresql-base-${PORTVERSION}${EXTRACT_SUFX} \
		postgresql-opt-${PORTVERSION}${EXTRACT_SUFX} \
		postgresql-test-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER?=	seanc@FreeBSD.org

WRKSRC=		${WRKDIR}/postgresql-${PORTVERSION}
DIST_SUBDIR=	postgresql

USE_GMAKE=	YES
GNU_CONFIGURE=	YES

.if defined(POSTGRESQL_SUBPORT)
## the POSTGRESQL_SUBPORTS use this port's distinfo
MD5_FILE=	${.CURDIR}/../postgresql-devel/distinfo
.else

## The rest of this file is for normal base installation
INSTALLS_SHLIB=	YES

CONFIGURE_ARGS=	--docdir=${PREFIX}/share/doc --with-libdir=${LOCALBASE}/lib \
		--with-includes=${LOCALBASE}/include

.if !defined(WITHOUT_GNUGETOPT)
LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt
.endif

# if you want localized messages, make -DWITH_GETTEXT
# WARNING: this seems to require relinking binaries depending on
# libpq.so, including for example mod_php and tcl.
.if defined(WITHOUT_GETTEXT)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	GETTEXT=""
.else
CONFIGURE_ENV+=	"LDFLAGS=-L${LOCALBASE}/lib"
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--enable-nls
LIB_DEPENDS+=	intl.4:${PORTSDIR}/devel/gettext
PLIST_SUB+=	GETTEXT="@comment "
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+= -O3 -funroll-loops
.endif

.if defined(WITH_DEBUG) && defined(WITH_STRIPBIN)
	@${ECHO} "WITH_DEBUG and WITH_STRIPBIN are mutually exclusive tunables."
	@${ECHO} "Please choose one or the other."
	@exit ${FALSE}
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_STRIPBIN)
INSTALL_TARGET=	install-strip
.endif

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+= "--with-openssl=${OPENSSLBASE}"
.endif

.if defined(WITH_MIT_KRB5) && defined(WITH_HEIMDAL_KRB5)
	@${ECHO} "WITH_MIT_KRB5 and WITH_HEIMDAL_KRB5 are mutually exclusive."
	@${ECHO} "Please choose one or the other."
	@exit 1
.endif

.if defined(WITH_MIT_KRB5)
KRB5CONF=	${LOCALBASE}/bin/krb5-config
.if !exists(${KRB5CONFIG})
	@${ECHO} "Unable to find krb5-config in your local base, please verify that"
	@${ECHO} "security/krb5 is installed or undefine the WITH_MIT_KRB5 tunable."
	@exit 1
.endif
WITH_KRB5=	yes
.endif

.if defined(WITH_HEIMDAL_KRB5)
KRB5CONF=	/usr/bin/krb5-config
.if !exists(${KRB5CONFIG})
	@${ECHO} "Unable to find krb5-config in the base system.  Undefine"
	@${ECHO} "WITH_HEIMDAL_KRB5 or add MAKE_KERBEROS5=yes to /etc/make.conf"
	@${ECHO} "and remake world (or undefine the WITH_HEIMDAL_KRB5 tunable)."
	@exit 1
.endif
LIB_DEPENDS+=	krb5.3:${PORTSDIR}/security/krb5
WITH_KRB5=	yes
.endif

.if defined(WITH_KRB5)
CONFIGURE_ARGS+=	--with-krb5="`${KRB5CONF} --prefix krb5`"
LDFLAGS+=	`${KRB5CONF} --libs krb5`
.endif

.if defined(WITHOUT_SERVER)
PKGMESSAGE=	${PKGDIR}/pkg-message.client
PLIST_SUB+=	SERVER="@comment "
.else
PLIST_SUB+=	SERVER=""
.endif

pre-everything::
	@${ECHO} ""
	@${ECHO} "CAUTION!!!!!"
	@${ECHO} ""
	@${ECHO} "	This is a development port!  You will have to re-initdb between"
	@${ECHO} "	upgrades as the system catalogs have changed between snapshots."
	@${ECHO} ""
	@${ECHO} "	Running this version of the port implies a large degree of"
	@${ECHO} "	familiarity with the PostgreSQL development cycle and process."
	@${ECHO} "	You should _always_ backup your data using pg_dump(all) before"
	@${ECHO} "	every upgrade.  If you have not backed up your data yet, exit"
	@${ECHO} "	this installation and backup your data now!!!!"
	@${ECHO} ""
	@${ECHO} ""
	@${ECHO} "${PORTNAME} has several tunables that used to configure PostgreSQL:"
	@${ECHO} ""
	@${ECHO} "	WITHOUT_GNUGETOPT=yes		Skips building with GNU getopt"
	@${ECHO} "	WITHOUT_GETTEXT=yes		Skips building with support for"
	@${ECHO} "					internationalized error messages"
	@${ECHO} "	WITH_DEBUG=yes			Builds with debugging symbols"
	@${ECHO} "	WITH_STRIPBIN=yes		Installs stripped binaries"
	@${ECHO} "	WITHOUT_SSL=yes			Builds without OpenSSL support"
	@${ECHO} "	WITHOUT_SERVER=yes		Installs the headers and libraries for"
	@${ECHO} "					PostgreSQL clients"
	@${ECHO} "	WITH_MIT_KRB5=yes		Builds with MIT's kerberos support"
	@${ECHO} "	WITH_HEIMDAL_KRB5=yes		Builds with Heimdal's kerberos support"
	@${ECHO} "	WITH_OPTIMIZED_CFLAGS=yes	Builds with compiler optimizations (-O3)"
	@${ECHO} ""
.if !defined(BATCH)
	@sleep 5
.endif

pre-install:
.if !defined(WITHOUT_SERVER)
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/pkg-install ${PORTNAME} PRE-INSTALL
.endif

post-install:
	@ ${MKDIR} ${PREFIX}/share/postgresql ;\
	${CAT} ${FILESDIR}/post-install-notes ${PKGMESSAGE} |\
		${SED} "s|/usr/local|${PREFIX}|g" |\
		tee ${PREFIX}/share/postgresql/post-install-notes
.if !defined(DEBUG_FLAGS)
.for file in ecpg pg_dump pg_id pg_restore psql
	@ strip ${PREFIX}/bin/${file}
.endfor
.endif
.if !defined(WITHOUT_SERVER)
# install shell defaults for pgsql user
	@ strip ${PREFIX}/bin/postgres
.for i in profile cshrc
	@ ${SED} "s|%%PREFIX%%|${PREFIX}|g" \
		< ${FILESDIR}/dot.$i.in \
		> ${PREFIX}/share/postgresql/dot.$i.dist; \
	${CP} ${PREFIX}/share/postgresql/dot.$i.dist ~pgsql/; \
	if [ ! -f ~pgsql/.$i ]; then \
		${CP} ${PREFIX}/share/postgresql/dot.$i.dist ~pgsql/.$i; \
	fi
.endfor
	@ ${SED} -e "s|%%PREFIX%%|${PREFIX}|g; s|%%PG_PREFIX%%|${PG_PREFIX}|g" \
		< ${FILESDIR}/pgsql.sh.tmpl \
		> ${PREFIX}/etc/rc.d/010.pgsql.sh ;\
	${CHMOD} 554 ${PREFIX}/etc/rc.d/010.pgsql.sh ;\
	${CHOWN} root:pgsql ${PREFIX}/etc/rc.d/010.pgsql.sh ;\
	${INSTALL_DATA} ${PREFIX}/share/postgresql/post-install-notes ~pgsql/. ;\
	${CHOWN} -R pgsql:pgsql ~pgsql/. ;\
	${INSTALL_DATA} ${FILESDIR}/502.pgsql \
			${PREFIX}/share/postgresql
.else
do-install:
	@ cd ${WRKSRC}; \
	${GMAKE} -C src/bin ${INSTALL_TARGET} ;\
	${GMAKE} -C src/include ${INSTALL_TARGET} ;\
	${GMAKE} -C src/interfaces ${INSTALL_TARGET}
.endif

post-clean:
	@ ${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

check:
	@ cd ${WRKSRC}; \
	${GMAKE} check

.include <bsd.port.mk>
.endif
