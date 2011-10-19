# New ports collection makefile for:    firebird25-server
# Date created:         2010-12-20
# Whom:                 Alonso Cárdenas Márquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	firebird
PORTVERSION=	2.5.1
PORTREVISION?=	0
CATEGORIES?=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:S/.0//}-Release/
PKGNAMESUFFIX?=	-server
DISTNAME=	${PORTNAME:S/f/F/}-${PORTVERSION}.26351-0
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT?=	Firebird-2 relational database (server)

LIB_DEPENDS=	icuuc:${PORTSDIR}/devel/icu

LATEST_LINK=	${PORTNAME}25${PKGNAMESUFFIX}

USE_BISON=	build
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	--with-system-editline \
		--with-system-icu \
		--prefix=${LOCALSTATEDIR} \
		--exec-prefix=${PREFIX} \
		--with-fbconf=${CONFDIR} \
		--with-fbglock=${LOCALSTATEDIR} \
		--with-fbhelp=${LOCALSTATEDIR}/help \
		--with-fbintl=${LIBEXECDIR}/intl \
		--with-fblog=${LOCALSTATEDIR} \
		--with-fbmsg=${DATADIR} \
		--with-fbplugins=${LIBEXECDIR}/plugins \
		--with-fbsbin=${PREFIX}/sbin \
		--with-fbsecure-db=${LOCALSTATEDIR} \
		--with-fbudf=${LIBEXECDIR}/UDF
CONFIGURE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

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
CONFLICTS+=	firebird-client-2.0* firebird-server-2.0* \
		firebird-client-2.1* firebird-server-2.1*

INSTALL_FB=	${INSTALL} ${COPY} -g firebird
IPCRM_CMD=	/usr/bin/ipcrm
IPCS_CMD=	/usr/bin/ipcs

IPCCHECK!=	${IPCRM_CMD} -q 0 2>&1 || true
.if ${IPCCHECK:Mimplemented}
IGNORE=		your system does not support sysvipc
.endif

.if !defined(CLIENT_ONLY)
# Server part stuff
LIB_DEPENDS+=	fbembed.2:${PORTSDIR}/databases/firebird25-client

ALL_TARGET=	firebird_embedded

USE_RC_SUBR=	firebird
SUB_FILES=	pkg-install pkg-message

UTIL_SBIN=	fb_inet_server fb_lock_print fb_smp_server
UTIL_BIN=	fbguard fbstat fbsvcmgr fbtracemgr gbak gdef gfix gsec gsplit \
		nbackup
UDF_SO=		ib_udf.so fbudf.so
UDF_SQL=	src/extlib/ib_udf2.sql src/extlib/fbudf/fbudf.sql
.else
# Client part stuff
ALL_TARGET=	firebird_basic libfbembed libfbclient embed_isql embed_gpre \
		embed_gdef embed_qli extlib

USE_LDCONFIG=	yes
CLIENT_BIN=	gpre isql-fb qli

.if !defined(NOPORTDOCS)
PORTDOCS=	*
FB_DOCS_FILES=	WhatsNew README.* Firebird* ReleaseNotes.pdf ambiguity.txt \
		ods11-index-structure.html
FB_DOCS_DIRS=	sql.extensions license upgrade
.endif
.endif

MAKE_ENV+=	FIREBIRD_TMP="${WRKDIR}" FIREBIRD_LOCK="${WRKDIR}"

post-extract:
	@${RM} -rf ${WRKSRC}/extern/icu

post-patch:
	${FIND} ${WRKSRC} -name "*.sh" -exec ${CHMOD} +x {} \+
	${REINPLACE_CMD} -e \
			's|/isql|/isql-fb|g' -e \
			's|/gstat|/fbstat|g' ${WRKSRC}/builds/posix/make.defaults

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-DAMD64
.endif

.if !defined(CLIENT_ONLY)

USERS=	${PORTNAME}
GROUPS=	${USERS}

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
	${MAKE} -C ${WRKSRC}/extern/btyacc
	[ -f ${WRKDIR}/ipcs.pre.build ] || ${IPCS_CMD} -s | ${TAIL} -n +3 | \
		${GREP} -F `${ID} -un` | ${CAT} > ${WRKDIR}/ipcs.pre.build

post-build:
	${IPCS_CMD} -s | ${TAIL} -n +3 | ${GREP} -F `${ID} -un` | ${CAT} > ${WRKDIR}/ipcs.post.build
	${DIFF} -n ${WRKDIR}/ipcs.pre.build ${WRKDIR}/ipcs.post.build  | \
		${TAIL} -n +2 | ${SED} -E 's/^s +([0-9]+).*$$/\/usr\/bin\/ipcrm -s \1/' > ${WRKDIR}/ipcrm.sh
	${SH} ${WRKDIR}/ipcrm.sh
.endif

do-install:
.if !defined(CLIENT_ONLY)

	${INSTALL_PROGRAM} ${UTIL_BIN:S!^!${WRKSRC}/gen/firebird/bin/!} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${UTIL_SBIN:S!^!${WRKSRC}/gen/firebird/bin/!} ${PREFIX}/sbin

	@${MKDIR} ${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/gen/install/misc/aliases.conf ${CONFDIR}/aliases.conf.sample
.if !exists(${CONFDIR}/aliases.conf)
	${INSTALL_DATA} ${WRKSRC}/gen/install/misc/aliases.conf ${CONFDIR}/aliases.conf
.endif
	${INSTALL_DATA} ${WRKSRC}/gen/install/misc/fbintl.conf ${CONFDIR}/fbintl.conf
	${INSTALL_DATA} ${WRKSRC}/gen/install/misc/fbtrace.conf ${CONFDIR}/fbtrace.conf

	${MKDIR} ${LIBEXECDIR}/udf ${LOCALSTATEDIR}/help ${LIBEXECDIR}/intl \
		${LIBEXECDIR}/plugins

	${CHOWN} -R firebird:firebird ${LOCALSTATEDIR}

	${INSTALL_FB} -m 0555 ${UDF_SO:S!^!${WRKSRC}/gen/firebird/UDF/!} ${LIBEXECDIR}/udf
	${INSTALL_FB} -m 0444 ${UDF_SQL:S!^!${WRKSRC}/!} ${LIBEXECDIR}/udf
	${INSTALL_FB} -m 0555 ${WRKSRC}/gen/firebird/plugins/libfbtrace.so ${LIBEXECDIR}/plugins

.if !exists(${LOCALSTATEDIR}/security2.fdb)
	${INSTALL_FB} -m 0660 -o firebird ${WRKSRC}/gen/firebird/security2.fdb ${LOCALSTATEDIR}/security2.fdb
.endif
	${INSTALL_FB} -m 0660 -o firebird ${WRKSRC}/gen/firebird/security2.fdb ${LOCALSTATEDIR}/security2.fdb.sample

	${INSTALL_FB} -m 0440 ${WRKSRC}/gen/firebird/help/help.fdb ${LOCALSTATEDIR}/help

	${INSTALL_FB} -m 0555 ${WRKSRC}/gen/firebird/intl/libfbintl.so ${LIBEXECDIR}/intl/fbintl
.else
# defined CLIENT_ONLY
	${INSTALL_PROGRAM} ${CLIENT_BIN:S!^!${WRKSRC}/gen/firebird/bin/!} ${PREFIX}/bin

	${SED} -e "s=%%PREFIX%%=${PREFIX}=g" ${WRKSRC}/gen/install/misc/firebird.conf > ${WRKDIR}/firebird.conf

	@${MKDIR} ${CONFDIR}
.if !exists(${CONFDIR}/firebird.conf)
	${INSTALL_DATA} ${WRKDIR}/firebird.conf ${CONFDIR}
.endif
	${INSTALL_DATA} ${WRKDIR}/firebird.conf ${CONFDIR}/firebird.conf.sample

	${INSTALL_DATA} ${WRKSRC}/gen/firebird/lib/libib_util.so \
		${WRKSRC}/gen/firebird/lib/libfbclient.so.${PORTVERSION} \
		${WRKSRC}/gen/firebird/lib/libfbembed.so.${PORTVERSION} \
		${PREFIX}/lib

	${LN} -fs libfbclient.so.${PORTVERSION} ${PREFIX}/lib/libfbclient.so.2.5
	${LN} -fs libfbclient.so.${PORTVERSION} ${PREFIX}/lib/libfbclient.so.2
	${LN} -fs libfbclient.so.${PORTVERSION} ${PREFIX}/lib/libfbclient.so

	${LN} -fs libfbembed.so.${PORTVERSION} ${PREFIX}/lib/libfbembed.so.2.5
	${LN} -fs libfbembed.so.${PORTVERSION} ${PREFIX}/lib/libfbembed.so.2
	${LN} -fs libfbembed.so.${PORTVERSION} ${PREFIX}/lib/libfbembed.so

	${LN} -fs libfbembed.so.${PORTVERSION} ${PREFIX}/lib/libgds.so.2.5
	${LN} -fs libfbembed.so.${PORTVERSION} ${PREFIX}/lib/libgds.so.2
	${LN} -fs libfbembed.so.${PORTVERSION} ${PREFIX}/lib/libgds.so

	@${MKDIR} ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/gen/firebird/include/*.h ${PREFIX}/include

	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gen/firebird/*.msg ${DATADIR}

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${FB_DOCS_DIRS:S!^!${DOCSDIR}/!}
	@${INSTALL_DATA} ${FB_DOCS_FILES:S!^!${WRKSRC}/doc/!} ${DOCSDIR}
	@${LN} -sf ${DOCSDIR}/README.user ${DOCSDIR}/README
	@${INSTALL_DATA} ${WRKSRC}/doc/sql.extensions/* ${DOCSDIR}/sql.extensions
	@${INSTALL_DATA} ${WRKSRC}/doc/license/* ${DOCSDIR}/license
	@${INSTALL_DATA} ${WRKSRC}/src/misc/upgrade/v2/* ${DOCSDIR}/upgrade
.endif
.endif

.include <bsd.port.post.mk>
