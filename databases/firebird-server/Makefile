# New ports collection makefile for:	Firebird
# Date created:		20 December 2000
# Whom:			Geoffrey C. Speicher <geoff@sea-incorporated.com>
#
# $FreeBSD$
#

PORTNAME?=	firebird
PORTVERSION=	1.5.5
CATEGORIES?=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=firebird
PKGNAMESUFFIX?=	-server
DISTNAME=	firebird-1.5.5.4926

MAINTAINER=	skv@FreeBSD.org
COMMENT?=	The open-source InterBase(tm) 6.0 spin-off (Classic version)

LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

EXPIRATION_DATE=	2009-02-24
DEPRECATED=	no longer under development, please consider using Firebird2

USE_BISON=	build
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:262 aclocal:19 libtool:22
ACLOCAL_ARGS=	--acdir=${ACLOCAL_DIR} -I ${LOCALBASE}/share/aclocal
USE_GCC=	3.4

LOCALSTATEDIR=	/var/db/firebird
CONFDIR=	${PREFIX}/etc/firebird
LIBEXECDIR=	${PREFIX}/libexec/firebird
PLIST_SUB=	FIREBIRD_VERSION=${PORTVERSION} \
		LOCALSTATEDIR="var/db/firebird" CONFDIR="etc/firebird"

# Don't use ld for linking, use gcc
LD=	${CC}

# Don't strip binary files
STRIP=

ONLY_FOR_ARCHS=	i386 amd64
CONFLICTS=	firebird-client-2* firebird-server-2*

WRKSRC=		${WRKDIR}/${DISTNAME}

INSTALL_FB=	${INSTALL} ${COPY} -g firebird

.if !defined(CLIENT_ONLY)
# Server part stuff
LIB_DEPENDS+=	fbembed.1:${PORTSDIR}/databases/firebird-client

AUTOGENARGS=	--with-lock-manager

ALL_TARGET=	firebird_boot ref_databases msgs libfbembed intl otherfiles \
		inet_server extlib embed_gfix embed_gbak embed_gdef embed_util

SUB_FILES=	pkg-install pkg-message aliases.conf
SUB_LIST+=	LOCALSTATEDIR=${LOCALSTATEDIR}

SUID_BIN=	fb_inet_server fb_lock_mgr gds_drop
UTIL_BIN=	fb_lock_print gbak gdef gfix gsec gstat
UDF_SO=		ib_udf.so fbudf.so
UDF_SQL=	src/extlib/ib_udf.sql src/extlib/fbudf/fbudf.sql
.else
# Client part stuff
AUTOGENARGS=	--with-editline

ALL_TARGET=	firebird_basic libfbembed embed_isql embed_gpre \
		embed_gdef embed_qli libfbclient extlib
#ALL_TARGET=	firebird_basic libfbembed libfbclient \
#		client_gpre client_gdef client_isql client_qli extlib

USE_LDCONFIG=	yes
CLIENT_BIN=	gpre isql qli

CONFIGURE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" PTHREAD_LIBS="${PTHREAD_LIBS}"

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif
.endif

MAKE_ENV+=	FIREBIRD_TMP="${WRKDIR}" FIREBIRD_LOCK="${WRKDIR}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
IGNORE=		Client does not compile with GCC 4.2.  Please use firebird2 instead
.endif

.if !defined(CLIENT_ONLY)
pre-everything::
	@${ECHO_MSG} "NOTE: If the work directory is on an NFS mount, you will"
	@${ECHO_MSG} "require NFS client locking support for the build to"
	@${ECHO_MSG} "succeed. Currently this is only available on FreeBSD 5.0"
	@${ECHO_MSG} "or greater."
	@${ECHO_MSG}
	@${ECHO_MSG} "WARNING: The on-disk structure of the databases has"
	@${ECHO_MSG} "changed since version 1.0.x."
	@${ECHO_MSG} "Cancel this installation now and backup your databases"
	@${ECHO_MSG} "if you have not already done so."
.if !defined(BATCH)
	@sleep 2
.endif
.endif

.if !defined(CLIENT_ONLY)
pre-su-install:
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

post-install:
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}
.endif

.ifndef WITHOUT_IPC_CLEANUP
pre-build:
.ifndef PACKAGE_BUILDING
	@if [ `${ID} -u` -eq 0 ]; then \
	${ECHO_MSG} "==> Please do not build ${PORTNAME} as 'root' because this may cause conflicts with SysV semaphores of running services."; exit 1; fi
.endif
	[ -f ${WRKDIR}/ipcs.pre.build ] || /usr/bin/ipcs -s | ${TAIL} -n +3 | \
		${GREP} -F `${ID} -un` | ${CAT} > ${WRKDIR}/ipcs.pre.build

post-build:
	/usr/bin/ipcs -s | ${TAIL} -n +3 | ${GREP} -F `${ID} -un` | ${CAT} > ${WRKDIR}/ipcs.post.build
	/usr/bin/diff -n ${WRKDIR}/ipcs.pre.build ${WRKDIR}/ipcs.post.build  | \
		${TAIL} -n +2 | ${SED} -E 's/^s +([0-9]+).*$$/\/usr\/bin\/ipcrm -s \1/' > ${WRKDIR}/ipcrm.sh
	${SH} ${WRKDIR}/ipcrm.sh
.endif

do-configure:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} MAKE=${GMAKE}	\
	${AUTOTOOLS_VARS} ./autogen.sh --localstatedir=${LOCALSTATEDIR} \
		--prefix=${LOCALSTATEDIR} --exec-prefix=${PREFIX} \
		--libexecdir=${LIBEXECDIR} \
		--sysconfdir=${CONFDIR} --datadir=${DATADIR} ${AUTOGENARGS})

post-configure:
	@${REINPLACE_CMD} -e 's|__attribute__ ((__unused__));||' \
		${WRKSRC}/src/dsql/parse.cpp

do-install:
.if !defined(CLIENT_ONLY)

	${INSTALL_PROGRAM} ${UTIL_BIN:S!^!${WRKSRC}/gen/firebird/bin/!} ${PREFIX}/bin

	${INSTALL_PROGRAM} -o firebird -g firebird -m 6550 \
		${SUID_BIN:S!^!${WRKSRC}/gen/firebird/bin/!} ${PREFIX}/sbin

	@${MKDIR} ${CONFDIR}
	${INSTALL_DATA} ${WRKDIR}/aliases.conf ${CONFDIR}/aliases.conf.sample

	${MKDIR} ${LIBEXECDIR}/udf ${LOCALSTATEDIR}/help ${LIBEXECDIR}/intl

	${CHOWN} -R firebird:firebird ${LOCALSTATEDIR}

	${INSTALL_FB} -m 0555 ${UDF_SO:S!^!${WRKSRC}/gen/firebird/UDF/!} ${LIBEXECDIR}/udf
	${INSTALL_FB} -m 0444 ${UDF_SQL:S!^!${WRKSRC}/!} ${LIBEXECDIR}/udf

.if !exists(${LOCALSTATEDIR}/security.fdb)
	${INSTALL_FB} -m 0660 -o firebird ${WRKSRC}/gen/firebird/security.fdb \
		${LOCALSTATEDIR}/security.fdb
.endif
	${INSTALL_FB} -m 0660 -o firebird ${WRKSRC}/gen/firebird/security.fdb \
		${LOCALSTATEDIR}/security.fdb.sample

	${INSTALL_FB} -m 0440 ${WRKSRC}/gen/firebird/help/help.fdb \
		${LOCALSTATEDIR}/help

	${INSTALL_FB} -m 0555 ${WRKSRC}/gen/firebird/intl/libfbintl.so ${LIBEXECDIR}/intl/fbintl

	${INSTALL_DATA} ${FILESDIR}/RELNOTES ${LOCALSTATEDIR}
.else
# defined CLIENT_ONLY
	${INSTALL_PROGRAM} ${CLIENT_BIN:S!^!${WRKSRC}/gen/firebird/bin/!} \
		${PREFIX}/bin

	${SED} -e "s=%%PREFIX%%=${PREFIX}=g" ${WRKSRC}/gen/firebird/misc/firebird.conf > ${WRKDIR}/firebird.conf

	@${MKDIR} ${CONFDIR}
.if !exists(${CONFDIR}/firebird.conf)
	${INSTALL_DATA} ${WRKDIR}/firebird.conf ${CONFDIR}
.endif
	${INSTALL_DATA} ${WRKDIR}/firebird.conf ${CONFDIR}/firebird.conf.sample

	${INSTALL_DATA} ${WRKSRC}/gen/firebird/lib/libib_util.so \
		${WRKSRC}/gen/firebird/lib/libfbclient.so.${PORTVERSION} \
		${WRKSRC}/gen/firebird/lib/libfbembed.so.${PORTVERSION} \
		${PREFIX}/lib

	${LN} -fs libfbclient.so.${PORTVERSION} ${PREFIX}/lib/libfbclient.so.1
	${LN} -fs libfbclient.so.1 ${PREFIX}/lib/libfbclient.so

	${LN} -fs libfbembed.so.${PORTVERSION} ${PREFIX}/lib/libfbembed.so.1
	${LN} -fs libfbembed.so.1 ${PREFIX}/lib/libfbembed.so
	${LN} -fs libfbembed.so.1 ${PREFIX}/lib/libgds.so.1
	${LN} -fs libfbembed.so.1 ${PREFIX}/lib/libgds.so

	@${MKDIR} ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/gen/firebird/include/*.h ${PREFIX}/include

	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gen/firebird/*.msg ${DATADIR}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/sql.extensions
	${INSTALL_DATA} ${WRKSRC}/doc/WhatsNew ${WRKSRC}/doc/README.* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README.user ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/doc/sql.extensions/README.* ${DOCSDIR}/sql.extensions
.endif

	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/gen/firebird/examples/v5/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
