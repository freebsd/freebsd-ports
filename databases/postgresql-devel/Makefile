# New ports collection makefile for:	PostgreSQL
# Date created:		November 13, 1998
# Whom:			Marc G. Fournier <scrappy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	postgresql
PORTVERSION?=	7.5.2003.12.03
CATEGORIES?=	databases
MASTER_SITES=	http://freebsd.sean.chittenden.org/ports/ \
		http://people.freebsd.org/~seanc/ports/
PATCH_SITES=	http://people.FreeBSD.org/~seanc/patches/pgsql/
PKGNAMESUFFIX=	-devel
DIST_SUBDIR=	postgresql

MAINTAINER?=	seanc@FreeBSD.org
COMMENT=	Development snapshots of PostgreSQL's latest features

CONFLICTS=	postgresql7*
CONFIGURE_ENV+=	DOCBOOKSTYLE=${LOCALBASE}/share/sgml/docbook/3.1/
USE_BZIP2=	YES
USE_GMAKE=	YES
USE_PERL5_BUILD=	YES
GNU_CONFIGURE=	YES

WRKSRC=		${WRKDIR}/postgresql-${PORTVERSION}
.if defined(POSTGRESQL_SUBPORT)
## the POSTGRESQL_SUBPORTS use this port's distinfo
MD5_FILE=	${.CURDIR}/../postgresql-devel/distinfo
.else

## POSTGRESQL_SUBPORTS stops here
## The rest of this file is for normal base installation
INSTALLS_SHLIB=	YES

BUILD_DEPENDS+=	bison1875:${PORTSDIR}/devel/bison1875
CONFIGURE_ARGS=	--with-libraries=${LOCALBASE}/lib \
		--with-includes=${LOCALBASE}/include \
		--with-docdir=${LOCALBASE}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

.if !defined(WITHOUT_GNUGETOPT)
USE_GETOPT_LONG=yes
.endif

.if !defined(WITHOUT_GETTEXT)
CONFIGURE_ARGS+=--enable-nls
LIB_DEPENDS+=	intl.5:${PORTSDIR}/devel/gettext-old
PLIST_SUB+=	GETTEXT=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	GETTEXT="@comment "
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+= -O3 -funroll-loops
.endif

.if defined(WITH_PGBLOCKSIZE)
.if (${WITH_PGBLOCKSIZE} == "16K")
PATCHFILES+=	"patch-pgblocksize-16K"
.elif (${WITH_PGBLOCKSIZE} == "32K")
PATCHFILES+=	"patch-pgblocksize-32K"
.elif (${WITH_PGBLOCKSIZE} == "65K")
#	This block size doesn't work, for use by developers only!!!
PATCHFILES+=	"patch-pgblocksize-65K"
.endif
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
INSTALL_TARGET=	install
.else
INSTALL_TARGET=	install-strip
.endif

.if !defined(WITHOUT_PGCRYPTO)
PLIST_SUB+=	PGCRYPTO=""
.else
PLIST_SUB+=	PGCRYPTO="@comment "
.endif

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+= "--with-openssl"
.endif

.if defined(WITHOUT_SERVER)
PKGMESSAGE=	${PKGDIR}/pkg-message.client
PLIST_SUB+=	SERVER="@comment "
PKGNAMESUFFIX=	-client
.else
PLIST_SUB+=	SERVER=""
INSTALL_TARGET+=	install-all-headers
MAKEFILE=	GNUmakefile
.endif

.if defined(WITHOUT_SPINLOCKS)
CONFIGURE_ARGS+=	--disable-spinlocks
.endif

.if defined(WITH_CASSERT)
CONFIGURE_ARGS+=	--enable-cassert
.endif

.if defined(WITH_JDBC)
CONFIGURE_ARGS+=	--with-java
.endif

.if defined(WITH_KRB5)
CONFIGURE_ARGS+=	--with-krb5="`${KRB5CONF} --prefix krb5`"
LDFLAGS+=	`${KRB5CONF} --libs krb5`
.endif

.if defined(WITH_MIT_KRB5)
KRB5CONF=	${KRB5_HOME}/bin/krb5-config
WITH_KRB5=	yes
.endif

.if defined(WITH_HEIMDAL_KRB5)
KRB5CONF=	/usr/bin/krb5-config
LIB_DEPENDS+=	krb5.3:${PORTSDIR}/security/krb5
WITH_KRB5=	yes
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+= -O3 -funroll-loops
.endif

.if defined(WITH_PERL)
CONFIGURE_ARGS+=	--with-perl
.endif

.if defined(WITH_PYTHON)
CONFIGURE_ARGS+=	--with-python
.endif

.if defined(WITH_RENDEZVOUS)
CONFIGURE_ARGS+=	--with-rendezvous
.endif

.if defined(WITH_TCL)
CONFIGURE_ARGS+=	--with-tcl
.endif

pre-everything::
	@${SH} ${PKGDIR}/pkg-install ${PORTNAME} BACKUPWARNING
	@${ECHO} ""
	@${ECHO} "${PORTNAME} has several tunables that can be used to configure PostgreSQL:"
	@${ECHO} ""
	@${ECHO} "	WITH_CASSERT		Builds with C Asserts (debug opt, slows perf)"
	@${ECHO} "	WITH_DEBUG		Builds with debugging symbols"
	@${ECHO} "	WITH_HEIMDAL_KRB5	Builds with Heimdal's kerberos support"
	@${ECHO} "	WITH_JDBC		Builds with JDBC support"
	@${ECHO} "	WITH_MIT_KRB5		Builds with MIT's kerberos support"
	@${ECHO} "	WITH_OPTIMIZED_CFLAGS	Builds with compiler optimizations (-O3)"
	@${ECHO} "	WITH_PERL		Builds with pl/Perl support"
	@${ECHO} "	WITH_PYTHON		Builds with pl/Python support"
	@${ECHO} "	WITH_PGBLOCKSIZE	It's possible to change the blocksize to \"16K\""
	@${ECHO} "				or \"32K\" (defaults to 8K and different"
	@${ECHO} "				block sizes require a dump, initdb, reload!)"
	@${ECHO} "	WITH_RENDEZVOUS		Builds with Rendezvous support"
	@${ECHO} "	WITH_TCL		Builds with pl/tcl support"
	@${ECHO} "	WITHOUT_GETTEXT		Skips building with support for"
	@${ECHO} "				internationalized error messages"
	@${ECHO} "	WITHOUT_GNUGETOPT	Don't install GNU getopt (will"
	@${ECHO} "				still be used if already installed)"
	@${ECHO} "	WITHOUT_PGCRYPTO	Builds without pgcrypto support"
	@${ECHO} "	WITHOUT_SERVER		Installs the headers and libraries for"
	@${ECHO} "				PostgreSQL clients"
	@${ECHO} "	WITHOUT_SPINLOCKS	Builds without spin locks"
	@${ECHO} "	WITHOUT_SSL		Builds without OpenSSL support"
	@${ECHO} ""
	@${ECHO} ""
.if defined(WITH_MIT_KRB5) && defined(WITH_HEIMDAL_KRB5)
	@${ECHO} "WITH_MIT_KRB5 and WITH_HEIMDAL_KRB5 are mutually exclusive."
	@${ECHO} "Please choose one or the other."
	@exit 1
.endif
.if defined(WITH_MIT_KRB5) && !exists(${KRB5CONF})
	@${ECHO} "Unable to find krb5-config in your local base, please verify that"
	@${ECHO} "security/krb5 is installed or undefine the WITH_MIT_KRB5 tunable."
	@exit 1
.endif
.if defined(WITH_HEIMDAL_KRB5) && !exists(${KRB5CONF})
	@${ECHO} "Unable to find krb5-config in the base system.  Undefine"
	@${ECHO} "WITH_HEIMDAL_KRB5 or add MAKE_KERBEROS5=yes to /etc/make.conf"
	@${ECHO} "and remake world (or undefine the WITH_HEIMDAL_KRB5 tunable)."
	@exit 1
.endif

.if !defined(WITHOUT_PGCRYPTO)
post-build:
	${GMAKE} -C ${WRKSRC}/contrib/pgcrypto
.endif

.if defined(WITHOUT_SERVER)
do-install:
	@ cd ${WRKSRC}; \
	${GMAKE} -C src/bin ${INSTALL_TARGET} ;\
	${GMAKE} -C src/include ${INSTALL_TARGET} ;\
	${GMAKE} -C src/interfaces ${INSTALL_TARGET} ;\
	${GMAKE} -C doc ${INSTALL_TARGET}
.else
pre-install:
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/pkg-install ${PORTNAME} PRE-INSTALL
.endif

post-install:
.if !defined(WITHOUT_PGCRYPTO)
	${GMAKE} -C ${WRKSRC}/contrib/pgcrypto install
.endif
	@ ${MKDIR} ${PREFIX}/share/postgresql ;\
	${CAT} ${FILESDIR}/post-install-notes ${PKGMESSAGE} |\
		${SED} "s|/usr/local|${PREFIX}|g" |\
		tee ${PREFIX}/share/postgresql/post-install-notes
.if !defined(WITHOUT_SERVER)
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
.endif

check:
	@if [ `id -u` != 0 ] ; then \
		${ECHO} "Running postgresql regressions tests" ;\
		cd ${WRKSRC}; ${GMAKE} check ;\
	else \
		${ECHO} "You cannot run regression tests when postgresql is built as user root." ; \
		${ECHO} "Clean and rebuild the port as a regular user to run the tests." ;\
	fi

.include <bsd.port.mk>
.endif
