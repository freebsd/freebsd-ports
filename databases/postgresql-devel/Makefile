# New ports collection makefile for:	PostgreSQL
# Date created:		November 13, 1998
# Whom:			Marc G. Fournier <scrappy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	postgresql
PORTVERSION?=	7.4.2003.01.26
CATEGORIES?=	databases
MASTER_SITES=	http://freebsd.sean.chittenden.org/ports/
PKGNAMESUFFIX=	-devel

MAINTAINER?=	seanc@FreeBSD.org

DIST_SUBDIR=	postgresql

USE_BZIP2=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES

.if defined(POSTGRESQL_SUBPORT)
## the POSTGRESQL_SUBPORTS use this port's distinfo
MD5_FILE=	${.CURDIR}/../postgresql7/distinfo
.else

## POSTGRESQL_SUBPORTS stops here
## The rest of this file is for normal base installation
INSTALLS_SHLIB=	YES

CONFIGURE_ARGS=	--with-libraries=${LOCALBASE}/lib \
		--with-includes=${LOCALBASE}/include \
		--with-docdir=${LOCALBASE}/share/doc/$PORTNAME}${PKGNAMESUFFIX}

.if !defined(WITHOUT_GNUGETOPT)
LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt
.endif

.if !defined(WITHOUT_GETTEXT)
CONFIGURE_ARGS+=--enable-nls
LIB_DEPENDS+=	intl.4:${PORTSDIR}/devel/gettext
PLIST_SUB+=	GETTEXT=""
.else
CONFIGURE_ARGS+=--disable-nls
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

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+= "--with-openssl=${OPENSSLBASE}"
.endif

.if defined(WITHOUT_SERVER)
PKGMESSAGE=	${PKGDIR}/pkg-message.client
PLIST_SUB+=	SERVER="@comment "
PKGNAMESUFFIX=	-client
.else
PLIST_SUB+=	SERVER=""
INSTALL_TARGET=	install-all-headers
.if defined(WITH_STRIPBIN)
INSTALL_TARGET+=	install-strip
.else
INSTALL_TARGET+=	install
.endif
.endif

.if defined(WITH_MIT_KRB5)
KRB5CONF=	${LOCALBASE}/bin/krb5-config
WITH_KRB5=	yes
.endif

.if defined(WITH_HEIMDAL_KRB5)
KRB5CONF=	/usr/bin/krb5-config
LIB_DEPENDS+=	krb5.3:${PORTSDIR}/security/krb5
WITH_KRB5=	yes
.endif

.if defined(WITH_KRB5)
CONFIGURE_ARGS+=	--with-krb5="`${KRB5CONF} --prefix krb5`"
LDFLAGS+=	`${KRB5CONF} --libs krb5`
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+= -O3 -funroll-loops
.endif

pre-everything::
	@${SH} ${PKGDIR}/pkg-install ${PORTNAME} BACKUPWARNING
	@${ECHO} ""
	@${ECHO} "${PORTNAME} has several tunables that can be used to configure PostgreSQL:"
	@${ECHO} ""
	@${ECHO} "	WITHOUT_GNUGETOPT	Don't install GNU getopt (will"
	@${ECHO} "				still be used if already installed)"
	@${ECHO} "	WITHOUT_GETTEXT		Skips building with support for"
	@${ECHO} "				internationalized error messages"
	@${ECHO} "	WITHOUT_SERVER		Installs the headers and libraries for"
	@${ECHO} "				PostgreSQL clients"
	@${ECHO} "	WITHOUT_SSL		Builds without OpenSSL support"
	@${ECHO} "	WITH_MIT_KRB5		Builds with MIT's kerberos support"
	@${ECHO} "	WITH_HEIMDAL_KRB5	Builds with Heimdal's kerberos support"
	@${ECHO} "	WITH_OPTIMIZED_CFLAGS	Builds with compiler optimizations (-O3)"
	@${ECHO} "	WITH_DEBUG		Builds with debugging symbols"
	@${ECHO} "	WITH_STRIPBIN		Installs stripped binaries"
	@${ECHO} ""
.if defined(WITH_MIT_KRB5) && defined(WITH_HEIMDAL_KRB5)
	@${ECHO} "WITH_MIT_KRB5 and WITH_HEIMDAL_KRB5 are mutually exclusive."
	@${ECHO} "Please choose one or the other."
	@exit 1
.endif
.if defined(WITH_MIT_KRB5) && !exists(${KRB5CONFIG})
	@${ECHO} "Unable to find krb5-config in your local base, please verify that"
	@${ECHO} "security/krb5 is installed or undefine the WITH_MIT_KRB5 tunable."
	@exit 1
.endif
.if defined(WITH_HEIMDAL_KRB5) && !exists(${KRB5CONFIG})
	@${ECHO} "Unable to find krb5-config in the base system.  Undefine"
	@${ECHO} "WITH_HEIMDAL_KRB5 or add MAKE_KERBEROS5=yes to /etc/make.conf"
	@${ECHO} "and remake world (or undefine the WITH_HEIMDAL_KRB5 tunable)."
	@exit 1
.endif

.if defined(WITHOUT_SERVER)
do-install:
	@ cd ${WRKSRC}; \
	${GMAKE} -C src/bin ${INSTALL_TARGET} ;\
	${GMAKE} -C src/include ${INSTALL_TARGET} ;\
	${GMAKE} -C src/interfaces ${INSTALL_TARGET} ;\
	${GMAKE} -C doc ${INSTALL_TARGET}

pre-install:
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/pkg-install ${PORTNAME} PRE-INSTALL
.endif

post-install:
	@ ${MKDIR} ${PREFIX}/share/postgresql ;\
	${CAT} ${FILESDIR}/post-install-notes ${PKGMESSAGE} |\
		${SED} "s|/usr/local|${PREFIX}|g" |\
		tee ${PREFIX}/share/postgresql/post-install-notes
.if !defined(WITHOUT_SERVER)
# install shell defaults for pgsql user
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
	@ cd ${WRKSRC}; \
	${GMAKE} check

.include <bsd.port.mk>
.endif
