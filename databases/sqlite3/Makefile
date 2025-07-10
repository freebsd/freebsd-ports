PORTNAME=	sqlite3
DISTVERSION=	3.50.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	https://www.sqlite.org/${_YEAR}/ https://www2.sqlite.org/${_YEAR}/ https://www3.sqlite.org/${_YEAR}/
.if defined(TEA)
PKGNAMEPREFIX=	tcl-
.endif
DISTNAME=	sqlite-src-${PORTVERSION:C/\.([[:digit:]])[[:>:]]/0\1/g:S/.//g}00

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	SQL database engine in a C library
.if ${FLAVOR:U} == icu
COMMENT+=	(ICU flavor)
.endif
.if ${FLAVOR:U} == tcl
COMMENT+=	(TCL flavor)
.endif
.if defined(TEA)
COMMENT=	SQLite extension for Tcl using the Tcl Extension Architecture (TEA)
.endif
WWW=		https://www.sqlite.org/

LICENSE=	PD

.if !defined(TEA)
FLAVORS=	default icu tcl
FLAVOR?=	${FLAVORS:[1]}
icu_PKGNAMESUFFIX=	-${FLAVOR}	# databases/p5-DBD-SQLite with ICU support
tcl_PKGNAMESUFFIX=	-${FLAVOR}	# lang/tcl* support
.endif

USES=	libtool ncurses pathfix zip
USE_LDCONFIG=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--linemacros --soname=legacy OPTIONS='${_OPTIONS}'
# [The Chronicles of SONAME](https://sqlite.org/src/forumpost/5a3b44f510df8ded)
# [Set features OPTIONS for autosetup configurator](https://msteveb.github.io/autosetup/)

MAKE_JOBS_UNSAFE=	yes
ALL_TARGET+=	sqldiff
.if defined(TEA)
INSTALL_TARGET=	tcl_install
.endif
TEST_TARGET=	test

# The default numeric file permissions for newly created database files under unix.
# If not specified, the default is 0644 which means that the files is globally
# readable but only writable by the creator.
.ifdef DEFAULT_FILE_PERMISSIONS
CPPFLAGS+=	-DSQLITE_DEFAULT_FILE_PERMISSIONS=${DEFAULT_FILE_PERMISSIONS}
.endif

CONFLICTS_INSTALL=	sqlite3 sqlite3-icu sqlite3-tcl tcl-sqlite3 # include/sqlite3.h share/examples/sqlite3/example.tcl

SUB_FILES=	example.tcl
SUB_LIST=	TCLSH_CMD="${TCLSH}"

.if defined(TEA)
USES+=	sqlite
DESCR=	${MASTERDIR}/pkg-descr-tea
SUB_LIST+=	TEA="" NO_TEA="@comment "
PLIST_SUB+=	TEA="" NO_TEA="@comment "
.else
SUB_LIST+=	TEA="@comment " NO_TEA=""
PLIST_SUB+=	TEA="@comment " NO_TEA=""
.endif

PLIST_SUB+=	TCLVER=tcl${TCL_VER} TCLSUF=tcl${TCL_VER:S/.//g} DISTVERSION=${DISTVERSION}

# Compilation Options For SQLite https://www.sqlite.org/compile.html
OPTIONS_DEFINE=		EXAMPLES STRIP TCL THREADS
.if !defined(TEA)
OPTIONS_DEFINE+=	ARMOR DBPAGE DBSTAT DIRECT_READ DQS EXTENSION FTS3_TOKEN \
			FTS4 FTS5 LIKENOTBLOB MEMMAN METADATA NORMALIZE NULL_TRIM RBU SECURE_DELETE \
			SORT_REF STATIC STMT TRUSTED_SCHEMA UNKNOWN_SQL UNLOCK_NOTIFY \
			UPDATE_LIMIT URI URI_AUTHORITY
.endif
OPTIONS_DEFAULT=	DBPAGE DBSTAT DIRECT_READ EXTENSION FTS3_TOKEN FTS4 FTS5 LIBEDIT METADATA \
			RTREE SECURE_DELETE STRIP THREADS TS1 UNICODE61 UNLOCK_NOTIFY URI
# SECURE_DELETE, UNLOCK_NOTIFY, DBSTAT (since 41.0) used by www/firefox et al.
# RTREE used by graphics/mapnik, databases/spatialite
# FTS3_TOKEN used by audio/clementine-player, mail/thunderbird, www/seamonkey
# FTS5 used by sysutils/tracker
# JSON1 used by net-im/py-matrix-synapse (since SQLite 3.38.0 included by default)
# DBPAGE used by audio/audacity (since 3.0.0)
# DQS used by multimedia/emby-server, multimedia/tautulli, net/vnstat, www/qutebrowser
#
.if !defined(TEA)
OPTIONS_GROUP=		OPT_EXT OPT_FUNC RTREEG UNICODE
.endif
OPTIONS_GROUP_OPT_EXT=	SESSION
OPTIONS_GROUP_OPT_FUNC=	OFFSET SOUNDEX
OPTIONS_GROUP_RTREEG=	GEOPOLY RTREE RTREE_INT
OPTIONS_GROUP_UNICODE=	ICU UNICODE61
.if !defined(TEA)
OPTIONS_RADIO=		STAT RL
.endif
OPTIONS_RADIO_RL=	LIBEDIT READLINE
OPTIONS_RADIO_STAT=	STAT3 STAT4
.if !defined(TEA)
OPTIONS_SINGLE=		RAMT
.endif
OPTIONS_SINGLE_RAMT=	TS0 TS1 TS2 TS3
.if ${FLAVOR:U} == icu
OPTIONS_EXCLUDE=	UNICODE61
OPTIONS_SLAVE=		ICU
.endif
.if ${FLAVOR:U} == tcl || defined(TEA)
OPTIONS_SLAVE=		TCL
.endif
OPTIONS_SUB=		yes

ARMOR_DESC=		Detect misuse of the API # https://www.sqlite.org/compile.html#enable_api_armor
DBPAGE_DESC=		Enable DBPAGE Virtual Table # https://sqlite.org/compile.html#enable_dbpage_vtab
DBSTAT_DESC=		Enable DBSTAT Virtual Table # https://www.sqlite.org/dbstat.html
DIRECT_READ_DESC=	File is read directly from disk # https://sqlite.org/compile.html#direct_overflow_read
DQS_DESC=		Double-quoted String Literals # https://www.sqlite.org/compile.html#dqs
EXTENSION_DESC=		Enable loadable extensions
FTS3_TOKEN_DESC=	Enable two-args version fts3_tokenizer # https://www.sqlite.org/compile.html#enable_fts3_tokenizer, https://www.sqlite.org/fts3.html#f3tknzr
FTS4_DESC=		Enable FTS3/4 (Full Text Search) module # https://www.sqlite.org/fts3.html, https://www.sqlite.org/compile.html#enable_fts3_parenthesis
FTS5_DESC=		Enable version 5 full-text search engine # https://www.sqlite.org/fts5.html
GEOPOLY_DESC=		Uses the GeoJSON notation (RFC-7946) # https://www.sqlite.org/geopoly.html
LIKENOTBLOB_DESC=	LIKE does not match blobs # https://sqlite.org/compile.html#like_doesnt_match_blobs
MEMMAN_DESC=		Allow it to release unused memory
METADATA_DESC=		Enable column metadata
NORMALIZE_DESC=		Enable normalized sql function
NULL_TRIM_DESC=		Omits NULL columns at the ends of rows # https://sqlite.org/compile.html#enable_null_trim
OFFSET_DESC=		Enable sqlite_offset() returning records file offset # http://www.sqlite.org/compile.html#enable_offset_sql_func
OPT_EXT_DESC=		Optional extensions
OPT_FUNC_DESC=		Optional functions
RAMT_DESC=		Where to store temporary file # https://www.sqlite.org/tempfiles.html#tempstore
RBU_DESC=		Enable the resumable bulk update # https://www.sqlite.org/rbu.html
RL_DESC=		Command line editing library
RTREEG_DESC=		Index type for range queries # https://www.sqlite.org/rtree.html
RTREE_DESC=		Enable R*Tree module
RTREE_INT_DESC=		Store 32-bit sig int (no float) coordinates
SECURE_DELETE_DESC=	Overwrite deleted information with zeros
SESSION_DESC=		Enable the session extension # https://www.sqlite.org/sessionintro.html
SORT_REF_DESC=		To use references in the sorter # https://www.sqlite.org/compile.html#enable_sorter_references
SOUNDEX_DESC=		Enable the soundex() SQL function
STAT3_DESC=		Collect histogram data from leftmost column
STAT4_DESC=		Collect histogram data from all columns
STAT_DESC=		Which query planner to use, stability or ... # https://www.sqlite.org/queryplanner-ng.html#qpstab
STMT_DESC=		Prepared statement scan status # https://www.sqlite.org/c3ref/stmt_scanstatus.html
TCL_DESC=		Enable tcl extension and sqlite_analyzer
TRUSTED_SCHEMA_DESC=	SQL functions & virtual tables are considered unsafe # https://www.sqlite.org/compile.html#trusted_schema
TS0_DESC=		Always use temporary file
TS1_DESC=		File by default, change allowed PRAGMA
TS2_DESC=		Memory by default, change allowed PRAGMA
TS3_DESC=		Always use memory
UNICODE61_DESC=		Unicode Version 6.1 tokenizer # https://www.sqlite.org/fts3.html#tokenizer
UNKNOWN_SQL_DESC=	Suppress unknown function errors # http://sqlite.org/compile.html#enable_unknown_sql_function
UNLOCK_NOTIFY_DESC=	Enable notification on unlocking
UPDATE_LIMIT_DESC=	UPDATE/DELETE is extended with ORDER BY and LIMIT # https://www.sqlite.org/compile.html#enable_update_delete_limit
URI_AUTHORITY_DESC=	Allow convert URL into a UNC
URI_DESC=		Enable use the URI filename

ARMOR_CPPFLAGS=	-DSQLITE_ENABLE_API_ARMOR=1
DBPAGE_CPPFLAGS=	-DSQLITE_ENABLE_DBPAGE_VTAB=1
DBSTAT_CPPFLAGS=	-DSQLITE_ENABLE_DBSTAT_VTAB=1
DIRECT_READ_CPPFLAGS_OFF=	-DSQLITE_DIRECT_OVERFLOW_READ=0
DQS_CPPFLAGS=	-DSQLITE_DQS=3
DQS_CPPFLAGS_OFF=	-DSQLITE_DQS=0
EXTENSION_CONFIGURE_ENABLE=	load-extension
FTS3_TOKEN_CPPFLAGS=	-DSQLITE_ENABLE_FTS3_TOKENIZER=1
FTS4_CONFIGURE_ON=	--fts3 --fts4
FTS4_CPPFLAGS=	-DSQLITE_ENABLE_FTS3_PARENTHESIS=1
FTS5_CONFIGURE_ON=	--fts5
FTS5_VARS=	_OPTIONS+=-lm
GEOPOLY_IMPLIES=	RTREE
GEOPOLY_CONFIGURE_ON=	--geopoly
ICU_BUILD_DEPENDS=	${LOCALBASE}/bin/icu-config:devel/icu
ICU_LIB_DEPENDS=	libicudata.so:devel/icu
ICU_CONFIGURE_ON=	--with-icu-config=${LOCALBASE}/bin/icu-config --icu-collations
ICU_CPPFLAGS=		`${LOCALBASE}/bin/icu-config --cppflags`
LIBEDIT_USES=	libedit
LIBEDIT_CONFIGURE_ON=	--editline
LIKENOTBLOB_CPPFLAGS=	-DSQLITE_LIKE_DOESNT_MATCH_BLOBS=1
MEMMAN_CPPFLAGS=	-DSQLITE_ENABLE_MEMORY_MANAGEMENT=1
METADATA_CPPFLAGS=	-DSQLITE_ENABLE_COLUMN_METADATA=1
NORMALIZE_CPPFLAGS=	-DSQLITE_ENABLE_NORMALIZE=1
NULL_TRIM_CPPFLAGS=	-DSQLITE_ENABLE_NULL_TRIM=1
OFFSET_CPPFLAGS=	-DSQLITE_ENABLE_OFFSET_SQL_FUNC=1
RBU_CPPFLAGS=	-DSQLITE_ENABLE_RBU=1
READLINE_USES=	readline
READLINE_CONFIGURE_ENABLE=	readline
RTREE_CONFIGURE_ON=	--rtree
RTREE_INT_CPPFLAGS=	-DSQLITE_RTREE_INT_ONLY=1
SECURE_DELETE_CPPFLAGS=	-DSQLITE_SECURE_DELETE=1
SESSION_CONFIGURE_ON=	--session
SORT_REF_CPPFLAGS=	-DSQLITE_ENABLE_SORTER_REFERENCES=1
SOUNDEX_CPPFLAGS=	-DSQLITE_SOUNDEX=1
STAT3_CPPFLAGS=	-DSQLITE_ENABLE_STAT3=1
STAT4_CPPFLAGS=	-DSQLITE_ENABLE_STAT4=1
STATIC_CONFIGURE_OFF=	--dynlink-tools
STATIC_CONFIGURE_ENABLE=	static
STMT_CONFIGURE_ON=	--scanstatus
TCL_USES=	tcl
TCL_USES_OFF=	tcl:build
TCL_CONFIGURE_OFF=	--disable-tcl
TCL_CONFIGURE_ENV=	ac_cv_prog_TCLSH_CMD=${TCLSH}
TCL_ALL_TARGET+=	sqlite3_analyzer
THREADS_CONFIGURE_OFF=	--disable-threadsafe
THREADS_VARS=	_OPTIONS+=-lpthread
TRUSTED_SCHEMA_CPPFLAGS=	-DSQLITE_TRUSTED_SCHEMA=0
TS0_CONFIGURE_ON=	--with-tempstore=never
TS1_CONFIGURE_ON=	--with-tempstore=no
TS2_CONFIGURE_ON=	--with-tempstore=yes
TS3_CONFIGURE_ON=	--with-tempstore=always
UNICODE61_CPPFLAGS_OFF=	-DSQLITE_DISABLE_FTS3_UNICODE=1
UNKNOWN_SQL_CPPFLAGS=	-DSQLITE_ENABLE_UNKNOWN_SQL_FUNCTION=1
UNLOCK_NOTIFY_CPPFLAGS=	-DSQLITE_ENABLE_UNLOCK_NOTIFY=1
UPDATE_LIMIT_CONFIGURE_ON=	--update-limit
URI_CPPFLAGS=	-DSQLITE_USE_URI=1
URI_AUTHORITY_CPPFLAGS=	-DSQLITE_ALLOW_URI_AUTHORITY=1

.include <bsd.port.options.mk>

# _YEAR=	${%Y:L:gmtime} - do not work with the version from the previous year
_YEAR=	2025

# Recommended options
# https://sqlite.org/compile.html#strict_subtype
.if defined(SQLITE_STRICT_SUBTYPE)
CPPFLAGS+=	-DSQLITE_STRICT_SUBTYPE=${SQLITE_STRICT_SUBTYPE}
.else
# This recommended option helps to identify problems in the implementation of application-defined SQL functions early in the development cycle.
CPPFLAGS+=	-DSQLITE_STRICT_SUBTYPE=1
.endif

# Platform Configuration
# -DHAVE_POSIX_FALLOCATE=1 not yet, chunksize.test ZFS failure chunksize-1.2 expected: [32768] got: [2048]
CPPFLAGS+=	-DHAVE_FCHOWN=1 \
		-DHAVE_FDATASYNC=1 \
		-DHAVE_ISNAN=1 \
		-DHAVE_GMTIME_R=1 \
		-DHAVE_LOCALTIME_R=1 \
		-DHAVE_LSTAT=1 \
		-DHAVE_MALLOC_USABLE_SIZE=1 \
		-DHAVE_PREAD=1 \
		-DHAVE_PWRITE=1 \
		-DHAVE_USLEEP=1 \
		-DHAVE_STRCHRNUL=1 \
		-DHAVE_STRERROR_R=1 \
		-DHAVE_READLINK=1 \
		-DSQLITE_OS_UNIX=1

.if ${PORT_OPTIONS:MTCL}
LIB_DEPENDS+=	libtommath.so:math/libtommath
.endif

# For compare with checksum from of the site. Now, this is a NIST SHA3-256 hash. sha256 not suitable for compare.
# But the creation of a new target does not justify the emergence of dependence on the perl5.
# sha3sum maybe installed with p5-Digest-SHA3 port.
# EXTRACT_DEPENDS=p5-Digest-SHA3:security/p5-Digest-SHA3; USES=perl5; USE_PERL5=extract;
# @${PERL} -MDigest::SHA3 -le 'print Digest::SHA3->new(sha_256_hex)->add(<>)->hexdigest' < ${DISTDIR}/${ALLFILES}
post-fetch:
	@${WHICH} sha3sum > /dev/null && for entry in ${ALLFILES}; do ${ECHO_MSG} -n "=> "; sha3sum -a 256 --tag "${DISTDIR}/$${entry}"; done || ${TRUE}

post-configure:
	@${ECHO_MSG} "===> CONFIGURE_ARGS=${CONFIGURE_ARGS}"
	@${ECHO_MSG} "===> CFLAGS=${CFLAGS}"
	@${ECHO_MSG} "===> CPPFLAGS=${CPPFLAGS}"
	@${ECHO_MSG} "===> LDFLAGS=${LDFLAGS}"
	@${ECHO_MSG} "===> LIBS=${LIBS}"
	@${ECHO_MSG} "===> TCL_VER=${TCL_VER}"
	@${ECHO_MSG} "===> TCLSH=${TCLSH}"
	@${ECHO_MSG} "===> TCL_INCLUDEDIR=${TCL_INCLUDEDIR}"
	@${ECHO_MSG} "===> TCL_LIBDIR=${TCL_LIBDIR}"
	@${ECHO_MSG} "===> OPTIONS=${_OPTIONS}"

post-install:
.if !defined(TEA)
	${INSTALL_MAN} "${WRKSRC}/${PORTNAME}.1" "${STAGEDIR}${PREFIX}/share/man/man1"
	${RM} "${STAGEDIR}${PREFIX}/include/msvc.h"
	${SETENV} LD_LIBMAP_DISABLE=1 ldd -a "${STAGEDIR}${PREFIX}/bin/${PORTNAME}" "${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so"
	${INSTALL_PROGRAM} "${WRKSRC}/sqldiff" "${STAGEDIR}${PREFIX}/bin"
.else
	${RM} "${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.${DISTVERSION}" "${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.a"
.endif

post-install-STRIP-on:
.if !defined(TEA)
	${STRIP_CMD} "${STAGEDIR}${PREFIX}/bin/${PORTNAME}" "${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so"
.endif
.if ${PORT_OPTIONS:MTCL}
	${STRIP_CMD} "${STAGEDIR}${PREFIX}/lib/tcl${TCL_VER}/${PORTNAME}/libtcl${PORTNAME}.so"
.endif

post-install-TCL-on:
	${INSTALL_PROGRAM} "${WRKSRC}/${PORTNAME}_analyzer" "${STAGEDIR}${PREFIX}/bin"
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/mann
	${INSTALL_MAN} "${WRKSRC}/autoconf/tea/doc/${PORTNAME}.n" "${STAGEDIR}${PREFIX}/share/man/mann/${PORTNAME}.tcl${TCL_VER:S/.//g}.n"
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} "${STAGEDIR}${EXAMPLESDIR}"
	${INSTALL_SCRIPT} "${WRKDIR}/${SUB_FILES}" "${WRKSRC}/contrib/sqlitecon.tcl" "${STAGEDIR}${EXAMPLESDIR}"
.endif

pre-test:
.if ! ${PORT_OPTIONS:MTCL}
	@${ECHO_MSG} "===>  Option TCL must be On for test purposes" && ${FALSE}
.endif

.include <bsd.port.mk>
