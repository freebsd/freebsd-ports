PORTNAME=	firebird
PORTVERSION=	3.0.10
PORTREVISION=	4
CATEGORIES?=	databases
MASTER_SITES=	https://github.com/FirebirdSQL/${PORTNAME}/releases/download/v${PORTVERSION}/
PKGNAMESUFFIX?=	${PORTVERSION:R:S/.//}-server
DISTNAME=	${PORTNAME:S/f/F/}-${PORTVERSION}.33601-0
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT?=	Firebird-3 relational database (server)
WWW=		https://www.firebirdsql.org/

LICENSE=	IDPL IPL
LICENSE_COMB=	multi
LICENSE_NAME_IDPL=	Initial Developer's Public License
LICENSE_NAME_IPL=	InterBase Public License
LICENSE_FILE_IDPL=	${WRKSRC}/builds/install/misc/IDPLicense.txt
LICENSE_FILE_IPL=	${WRKSRC}/builds/install/misc/IPLicense.txt
LICENSE_PERMS_IDPL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_IPL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libtommath.so:math/libtommath

CONFLICTS_INSTALL=	firebird25 firebird40

USES=		cpe gmake pkgconfig localbase:ldflags libedit tar:bzip2
USE_CXXSTD=	gnu++03
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
CPE_VENDOR=	firebirdsql

CONFIGURE_ARGS=	--prefix=${LOCALSTATEDIR} \
		--exec-prefix=${PREFIX} \
		--with-fbbin=${PREFIX}/bin \
		--with-fblib=${PREFIX}/lib \
		--with-fbconf=${PREFIX}/${CONFDIR} \
		--with-fbglock=${LOCALSTATEDIR} \
		--with-fbhelp=${LOCALSTATEDIR}/help \
		--with-fbintl=${LIBEXECDIR}/intl \
		--with-fblog=${LOCALSTATEDIR} \
		--with-fbmsg=${DATADIR} \
		--with-fbplugins=${LIBEXECDIR}/plugins \
		--with-fbsbin=${PREFIX}/sbin \
		--with-fbsecure-db=${LOCALSTATEDIR} \
		--with-fbsample-db=${EXAMPLESDIR} \
		--with-fbudf=${LIBEXECDIR}/UDF
CONFIGURE_ENV+=	PTHREAD_LIBS="-lpthread" \
		ac_cv_header_atomic_ops_h="no" \
		ac_cv_lib_atomic_ops_main="no"
CPPFLAGS+=	-DU_NOEXCEPT= -fno-delete-null-pointer-checks # For USE_CXXSTD=gnu++98

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

INSTALL_FB=	${INSTALL} ${COPY}

.if !defined(CLIENT_ONLY)
# Server part stuff
USES+=		firebird:3.0

CONFIGURE_ARGS+=--without-editline

USE_RC_SUBR=	firebird
SUB_FILES=	pkg-message

UTIL_SBIN=	fbguard firebird
UTIL_BIN=	fb_lock_print fbsplit fbstat fbsvcmgr fbtracemgr gbak gfix gsec \
		nbackup
UDF_SO=		ib_udf.so fbudf.so
UDF_SQL=	ib_udf.sql ib_udf2.sql fbudf.sql
PLUGIN_SO=	libEngine12.so libfbtrace.so libLegacy_Auth.so \
		libLegacy_UserManager.so libSrp.so libudr_engine.so

PKGINSTALL?=	${PKGDIR}/pkg-install-server
.else
# Client part stuff
USES+=		libedit

CONFIGURE_ARGS+=	--with-system-editline
CONFIGURE_ENV+=	ac_cv_lib_edit_readline="yes"

USE_LDCONFIG=	yes
CLIENT_BIN=	gpre isql-fb qli
CLIENT_HEADER=	ib_util.h ibase.h iberror.h perf.h

OPTIONS_DEFINE=	DOCS

DOCS_PORTDOCS=	*

FB_DOCS_FILES=	WhatsNew README.* Firebird* ambiguity.txt \
		ods11-index-structure.html
FB_DOCS_DIRS=	sql.extensions license upgrade
.endif

MAKE_ENV+=	FIREBIRD_TMP="${WRKDIR}" FIREBIRD_LOCK="${WRKDIR}"
MAKE_ARGS+=	PREFIX="${STAGEDIR}${PREFIX}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-DAMD64
.endif

.if !defined(CLIENT_ONLY)
USERS=	${PORTNAME}
GROUPS=	${USERS}

#MAKE_ENV+=	IsServer=Y
.endif

post-patch:
	${FIND} ${WRKSRC} -name "*.sh" -exec ${CHMOD} +x {} \+
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/builds/install/misc/firebird.conf.in

pre-build:
.if !defined(CLIENT_ONLY)
	@${SETENV} PKG_PREFIX="${STAGEDIR}${PREFIX}" ${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL
.endif
	${MAKE} -C ${WRKSRC}/extern/btyacc

do-install:
.if !defined(CLIENT_ONLY)
	${INSTALL_PROGRAM} ${UTIL_BIN:S!^!${WRKSRC}/gen/Release/firebird/bin/!} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${UTIL_SBIN:S!^!${WRKSRC}/gen/Release/firebird/bin/!} ${STAGEDIR}${PREFIX}/sbin

	@${MKDIR} ${STAGEDIR}${PREFIX}/${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/gen/Release/firebird/databases.conf ${STAGEDIR}${PREFIX}/${CONFDIR}/databases.conf.sample
	${INSTALL_DATA} ${WRKSRC}/gen/Release/firebird/fbtrace.conf ${STAGEDIR}${PREFIX}/${CONFDIR}/fbtrace.conf
	${INSTALL_DATA} ${WRKSRC}/gen/Release/firebird/plugins.conf ${STAGEDIR}${PREFIX}/${CONFDIR}/plugins.conf.sample
	${INSTALL_DATA} ${WRKSRC}/gen/Release/firebird/plugins/udr_engine.conf ${STAGEDIR}${PREFIX}/${CONFDIR}/udr_engine.conf.sample

	${MKDIR} ${STAGEDIR}${LIBEXECDIR}/udf ${STAGEDIR}${LOCALSTATEDIR}/help ${STAGEDIR}${LIBEXECDIR}/intl \
		${STAGEDIR}${LIBEXECDIR}/plugins ${STAGEDIR}${EXAMPLESDIR}

	${INSTALL_DATA} ${WRKSRC}/gen/Release/firebird/lib/libib_util.so ${STAGEDIR}${PREFIX}/lib

	${INSTALL_DATA} ${WRKSRC}/gen/Release/firebird/intl/fbintl.conf ${STAGEDIR}${LIBEXECDIR}/intl/fbintl.conf
	${INSTALL_FB} -m 0555 ${UDF_SO:S!^!${WRKSRC}/gen/Release/firebird/UDF/!} ${STAGEDIR}${LIBEXECDIR}/udf
	${INSTALL_FB} -m 0444 ${UDF_SQL:S!^!${WRKSRC}/gen/Release/firebird/UDF/!} ${STAGEDIR}${LIBEXECDIR}/udf
	${INSTALL_FB} -m 0555 ${PLUGIN_SO:S!^!${WRKSRC}/gen/Release/firebird/plugins/!} ${STAGEDIR}${LIBEXECDIR}/plugins

	${INSTALL_FB} -m 0660 ${WRKSRC}/gen/Release/firebird/security3.fdb ${STAGEDIR}${LOCALSTATEDIR}/security3.fdb.sample
	${INSTALL_FB} -m 0660 ${WRKSRC}/gen/Release/firebird/examples/empbuild/employee.fdb ${STAGEDIR}${EXAMPLESDIR}/employee.fdb

	${INSTALL_FB} -m 0440 ${WRKSRC}/gen/Release/firebird/help/help.fdb ${STAGEDIR}${LOCALSTATEDIR}/help

	${INSTALL_FB} -m 0555 ${WRKSRC}/gen/Release/firebird/intl/libfbintl.so ${STAGEDIR}${LIBEXECDIR}/intl/libfbintl.so
.else
# defined CLIENT_ONLY
	${INSTALL_PROGRAM} ${CLIENT_BIN:S!^!${WRKSRC}/gen/Release/firebird/bin/!} ${STAGEDIR}${PREFIX}/bin

	${SED} -e "s=%%PREFIX%%=${PREFIX}=g" ${WRKSRC}/gen/Release/firebird/firebird.conf > ${WRKDIR}/firebird.conf

	@${MKDIR} ${STAGEDIR}${PREFIX}/${CONFDIR}
	${INSTALL_DATA} ${WRKDIR}/firebird.conf ${STAGEDIR}${PREFIX}/${CONFDIR}/firebird.conf.sample

	${INSTALL_DATA} ${WRKSRC}/gen/Release/firebird/lib/libfbclient.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib

	${LN} -fs libfbclient.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libfbclient.so.3
	${LN} -fs libfbclient.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libfbclient.so

	@${MKDIR} ${STAGEDIR}${PREFIX}/include/firebird
	${INSTALL_DATA} ${CLIENT_HEADER:S!^!${WRKSRC}/gen/Release/firebird/include/!} ${STAGEDIR}${PREFIX}/include

	@cd ${WRKSRC}/gen/Release/firebird/include/firebird && \
		${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${PREFIX}/include/firebird/{}" \;

	@cd ${WRKSRC}/gen/Release/firebird/include/firebird && \
		${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${STAGEDIR}${PREFIX}/include/firebird/{}" \;

	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gen/Release/firebird/*.msg ${STAGEDIR}${DATADIR}

post-install-DOCS-on:
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${FB_DOCS_DIRS:S!^!${STAGEDIR}${DOCSDIR}/!}
	${INSTALL_DATA} ${FB_DOCS_FILES:S!^!${WRKSRC}/doc/!} ${STAGEDIR}${DOCSDIR}
	${LN} -sf README.user ${STAGEDIR}${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/doc/sql.extensions/* ${STAGEDIR}${DOCSDIR}/sql.extensions
	${INSTALL_DATA} ${WRKSRC}/doc/license/* ${STAGEDIR}${DOCSDIR}/license
	${INSTALL_DATA} ${WRKSRC}/src/misc/upgrade/v3.0/* ${STAGEDIR}${DOCSDIR}/upgrade
.endif

.include <bsd.port.post.mk>
