# Created by: Alonso Cárdenas Márquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	firebird
PORTVERSION=	2.5.3
CATEGORIES?=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:S/.0//}-Release/
PKGNAMESUFFIX?=	${PORTVERSION:R:S/.//}-server
DISTNAME=	${PORTNAME:S/f/F/}-${PORTVERSION}.26778-0
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Firebird-2 relational database (server)

CONFLICTS?=	${PORTNAME}20-client-* \
		${PORTNAME}21-client-* \
		${PORTNAME}20-server-* \
		${PORTNAME}21-server-*

LIB_DEPENDS=	libicuuc.so:${PORTSDIR}/devel/icu

USES=		bison tar:bzip2 gmake
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	--with-system-editline \
		--with-system-icu \
		--prefix=${LOCALSTATEDIR} \
		--exec-prefix=${PREFIX} \
		--with-fbconf=${PREFIX}/${CONFDIR} \
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
CONFDIR=	etc/firebird
LIBEXECDIR=	${PREFIX}/libexec/firebird
PLIST_SUB=	FIREBIRD_VERSION=${PORTVERSION} \
		LOCALSTATEDIR="var/db/firebird" CONFDIR="${CONFDIR}"

# Don't use ld for linking, use gcc
LD=	${CC}

# Don't strip binary files
STRIP=

ONLY_FOR_ARCHS=	i386 amd64
CONFLICTS+=	firebird-client-2.0* firebird-server-2.0* \
		firebird-client-2.1* firebird-server-2.1*

INSTALL_FB=	${INSTALL} ${COPY}
IPCRM_CMD=	/usr/bin/ipcrm
IPCS_CMD=	/usr/bin/ipcs

IPCCHECK!=	${IPCRM_CMD} -q 0 2>&1 || true
.if ${IPCCHECK:Mimplemented}
IGNORE=		your system does not support sysvipc
.endif

.if !defined(CLIENT_ONLY)
# Server part stuff
LIB_DEPENDS+=	libfbembed.so:${PORTSDIR}/databases/firebird25-client

CONFIGURE_ARGS+=--enable-superserver

ALL_TARGET=	firebird_embedded firebird_server

USE_RC_SUBR=	firebird
SUB_FILES=	pkg-message

UTIL_SBIN=	fb_inet_server fb_lock_print fb_smp_server fbserver
UTIL_BIN=	fbguard fbsplit fbstat fbsvcmgr fbtracemgr gbak gdef gfix gsec \
		nbackup
UDF_SO=		ib_udf.so fbudf.so
UDF_SQL=	src/extlib/ib_udf2.sql src/extlib/fbudf/fbudf.sql

PKGINSTALL?=	${PKGDIR}/pkg-install-server
.else
# Client part stuff
ALL_TARGET=	firebird_basic libfbembed libfbclient embed_isql embed_gpre \
		embed_gdef embed_qli extlib

USE_LDCONFIG=	yes
CLIENT_BIN=	gpre isql-fb qli

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
FB_DOCS_FILES=	WhatsNew README.* Firebird* ReleaseNotes.pdf ambiguity.txt \
		ods11-index-structure.html
FB_DOCS_DIRS=	sql.extensions license upgrade
.endif
.endif

MAKE_ENV+=	FIREBIRD_TMP="${WRKDIR}" FIREBIRD_LOCK="${WRKDIR}"
MAKE_ARGS+=	PREFIX="${STAGEDIR}${PREFIX}"

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RM} -rf ${WRKSRC}/extern/icu

post-patch:
	${FIND} ${WRKSRC} -name "*.sh" -exec ${CHMOD} +x {} \+
	${REINPLACE_CMD} -e \
			's|/isql|/isql-fb|g' -e \
			's|/gstat|/fbstat|g' -e \
			's|/gsplit|/fbsplit|g' ${WRKSRC}/builds/posix/make.defaults

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-DAMD64
.endif

.if !defined(CLIENT_ONLY)
USERS=	${PORTNAME}
GROUPS=	${USERS}
.endif

.ifndef WITHOUT_IPC_CLEANUP
pre-build:
.if !defined(CLIENT_ONLY)
	@${SETENV} PKG_PREFIX="${STAGEDIR}${PREFIX}" ${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL
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

	${INSTALL_PROGRAM} ${UTIL_BIN:S!^!${WRKSRC}/gen/firebird/bin/!} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${UTIL_SBIN:S!^!${WRKSRC}/gen/firebird/bin/!} ${STAGEDIR}${PREFIX}/sbin

	@${MKDIR} ${STAGEDIR}${PREFIX}/${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/gen/install/misc/aliases.conf ${STAGEDIR}${PREFIX}/${CONFDIR}/aliases.conf.sample
	${INSTALL_DATA} ${WRKSRC}/gen/install/misc/fbtrace.conf ${STAGEDIR}${PREFIX}/${CONFDIR}/fbtrace.conf

	${MKDIR} ${STAGEDIR}${LIBEXECDIR}/udf ${STAGEDIR}${LOCALSTATEDIR}/help ${STAGEDIR}${LIBEXECDIR}/intl \
		${STAGEDIR}${LIBEXECDIR}/plugins

	${INSTALL_DATA} ${WRKSRC}/gen/install/misc/fbintl.conf ${STAGEDIR}${LIBEXECDIR}/intl/fbintl.conf
	${INSTALL_FB} -m 0555 ${UDF_SO:S!^!${WRKSRC}/gen/firebird/UDF/!} ${STAGEDIR}${LIBEXECDIR}/udf
	${INSTALL_FB} -m 0444 ${UDF_SQL:S!^!${WRKSRC}/!} ${STAGEDIR}${LIBEXECDIR}/udf
	${INSTALL_FB} -m 0555 ${WRKSRC}/gen/firebird/plugins/libfbtrace.so ${STAGEDIR}${LIBEXECDIR}/plugins

	${INSTALL_FB} -m 0660 ${WRKSRC}/gen/firebird/security2.fdb ${STAGEDIR}${LOCALSTATEDIR}/security2.fdb.sample

	${INSTALL_FB} -m 0440 ${WRKSRC}/gen/firebird/help/help.fdb ${STAGEDIR}${LOCALSTATEDIR}/help

	${INSTALL_FB} -m 0555 ${WRKSRC}/gen/firebird/intl/libfbintl.so ${STAGEDIR}${LIBEXECDIR}/intl/fbintl.so
.else
# defined CLIENT_ONLY
	${INSTALL_PROGRAM} ${CLIENT_BIN:S!^!${WRKSRC}/gen/firebird/bin/!} ${STAGEDIR}${PREFIX}/bin

	${SED} -e "s=%%PREFIX%%=${PREFIX}=g" ${WRKSRC}/gen/install/misc/firebird.conf > ${WRKDIR}/firebird.conf

	@${MKDIR} ${STAGEDIR}${PREFIX}/${CONFDIR}
	${INSTALL_DATA} ${WRKDIR}/firebird.conf ${STAGEDIR}${PREFIX}/${CONFDIR}/firebird.conf.sample

	${INSTALL_DATA} ${WRKSRC}/gen/firebird/lib/libib_util.so \
		${WRKSRC}/gen/firebird/lib/libfbclient.so.${PORTVERSION} \
		${WRKSRC}/gen/firebird/lib/libfbembed.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib

	${LN} -fs libfbclient.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libfbclient.so.2.5
	${LN} -fs libfbclient.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libfbclient.so.2
	${LN} -fs libfbclient.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libfbclient.so

	${LN} -fs libfbembed.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libfbembed.so.2.5
	${LN} -fs libfbembed.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libfbembed.so.2
	${LN} -fs libfbembed.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libfbembed.so

	${LN} -fs libfbembed.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libgds.so.2.5
	${LN} -fs libfbembed.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libgds.so.2
	${LN} -fs libfbembed.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libgds.so

	@${MKDIR} ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/gen/firebird/include/*.h ${STAGEDIR}${PREFIX}/include

	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gen/firebird/*.msg ${STAGEDIR}${DATADIR}

.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${FB_DOCS_DIRS:S!^!${STAGEDIR}${DOCSDIR}/!}
	@${INSTALL_DATA} ${FB_DOCS_FILES:S!^!${WRKSRC}/doc/!} ${STAGEDIR}${DOCSDIR}
	@${LN} -sf ${DOCSDIR}/README.user ${STAGEDIR}${DOCSDIR}/README
	@${INSTALL_DATA} ${WRKSRC}/doc/sql.extensions/* ${STAGEDIR}${DOCSDIR}/sql.extensions
	@${INSTALL_DATA} ${WRKSRC}/doc/license/* ${STAGEDIR}${DOCSDIR}/license
	@${INSTALL_DATA} ${WRKSRC}/src/misc/upgrade/v2/* ${STAGEDIR}${DOCSDIR}/upgrade
.endif
.endif

.include <bsd.port.post.mk>
