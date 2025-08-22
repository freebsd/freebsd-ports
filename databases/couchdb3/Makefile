PORTNAME=	couchdb3
DISTVERSION=	3.5.0
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	APACHE/couchdb/source/${DISTVERSION}
DISTNAME=	apache-couchdb-${DISTVERSION}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	JSON document database with HTTP API and scalable cluster mesh sync
WWW=		https://couchdb.apache.org/

LICENSE=	APACHE20 BSD3CLAUSE ISCL OFL11 WTFPL
LICENSE_COMB=	multi

# not supported upstream
NOT_FOR_ARCHS=	i386

BUILD_DEPENDS=	erlang-runtime${_ERLVER}>=${_ERLVER}.0:lang/erlang-runtime${_ERLVER} \
		rebar:devel/rebar
LIB_DEPENDS=	libicudata.so:devel/icu \
		libmozjs-102.so:lang/spidermonkey102

USES=		compiler:c++17-lang cpe gmake libtool ncurses
CPE_VENDOR=	apache
CPE_PRODUCT=	couchdb
USE_RC_SUBR=	${PORTNAME}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--skip-deps \
		--user ${USERS} \
		--rebar ${LOCALBASE}/bin/rebar \
		--spidermonkey-version 102

MAKE_ENV=	PATH=${LOCALBASE}/lib/erlang${_ERLVER}/bin:${PATH}
ALL_TARGET=	release

CONFLICTS=	couchdb[24]*

SUB_FILES=	pkg-message
SUB_LIST=	APPDIR=${_APPDIR} \
		ERL_PATH=${LOCALBASE}/lib/erlang${_ERLVER}/bin/erl \
		PORTNAME=${PORTNAME} \
		RELDIR=${_RELDIR} \
		WWWDIR=${WWWDIR}

USERS=		couchdb
GROUPS=		couchdb

PLIST_SUB=	VERSION=${DISTVERSION}

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

_APPDIR=	${LOCALBASE}/libexec/${PORTNAME}
_DBDIR?=	/var/db/${PORTNAME}
_ERLVER?=	27
_LOGDIR?=	/var/log/${PORTNAME}
_LOGFILE?=	${_LOGDIR}/couch.log
_RELDIR=	${_APPDIR}/releases/${DISTVERSION}
_RUNDIR=	/var/run/${PORTNAME}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${ARCH} == i386
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src_jiffy_c__src_double-conversion_strtod.cc
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's,%%APPDIR%%,${_APPDIR},g' \
		-e 's,%%COUCHDB_USER%%,${USERS},g' \
		-e 's,%%DATADIR%%,${_DATADIR},g' \
		-e 's,%%DBDIR%%,${_DBDIR},g' \
		-e 's,%%ERLVER%%,${_ERLVER},g' \
		-e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		-e 's,%%LOG_FILE%%,${_LOGFILE},g' \
		-e 's,%%PORTNAME%%,${PORTNAME},g' \
		-e 's,%%WWWDIR%%,${WWWDIR},g' \
		${WRKSRC}/configure
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=238514
.if ${OPSYS} == FreeBSD && ${ARCH} == i386
	@${REINPLACE_CMD} -e 's,$$FLTO_FLAG ,,g' \
		${WRKSRC}/src/jiffy/rebar.config
.endif

pre-install:
# prune build artefacts and surplus headers
	${FIND} -E ${WRKSRC} -type f -regex '.*\.(a|buildinfo|c|cc|cmd|d|o|orig|h|cpp)' \
		-print -delete

do-install:
# relocate user-modifiable runtime configs to match hier(7)
	${MKDIR} ${STAGEDIR}${ETCDIR} \
		${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/rel/couchdb/etc/local.ini \
		${STAGEDIR}${ETCDIR}/local.ini.sample
	${INSTALL_DATA} ${WRKSRC}/rel/couchdb/etc/vm.args \
		${STAGEDIR}${ETCDIR}/vm.args.sample
	${INSTALL_MAN} ${WRKSRC}/share/docs/man/apachecouchdb.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${CP} ${WRKSRC}/src/docs/images/favicon.ico ${WRKSRC}/share/www/
# remove runtime dirs and files that were moved to match hier(7)
	${RM} -r \
		${WRKSRC}/rel/couchdb/erts-*/include \
		${WRKSRC}/rel/couchdb/erts-*/src \
		${WRKSRC}/rel/couchdb/etc/*.d \
		${WRKSRC}/rel/couchdb/etc/local.ini \
		${WRKSRC}/rel/couchdb/etc/vm.args \
		${WRKSRC}/rel/couchdb/lib/couch-*/priv/couch_js/1.8.5 \
		${WRKSRC}/rel/couchdb/lib/couch-*/priv/couch_js/60 \
		${WRKSRC}/rel/couchdb/lib/couch-*/priv/couch_js/68 \
		${WRKSRC}/rel/couchdb/lib/couch-*/priv/couch_js/86 \
		${WRKSRC}/rel/couchdb/lib/couch-*/priv/couch_js/91 \
		${WRKSRC}/rel/couchdb/lib/couch-*/priv/priv/couchjs \
		${WRKSRC}/rel/couchdb/releases/*/vm.args \
		${WRKSRC}/rel/couchdb/share/docs \
		${WRKSRC}/rel/couchdb/share/www \
		${WRKSRC}/rel/couchdb/var
	(cd ${WRKSRC}/rel/couchdb && \
		${COPYTREE_SHARE} . ${STAGEDIR}${_APPDIR})
# strip binaries, and mark as executable, along with scripts
# -- this was not as straightforward as it could have been
	${FIND} ${STAGEDIR}${_APPDIR} -type f -name 'couchjs*' -exec ${STRIP_CMD} \
		{} +
	${FIND} ${STAGEDIR}${_APPDIR} -type f -name '*.so' -exec ${STRIP_CMD} \
		{} +
	${FIND} ${STAGEDIR}${_APPDIR}/erts-*/bin -type f -not -name start \
		-exec ${STRIP_CMD} {} +
	${STRIP_CMD} ${STAGEDIR}${_APPDIR}/lib/os_mon-*/priv/bin/*sup
	${CHMOD} -R ${BINMODE} ${STAGEDIR}${_APPDIR}/bin
	${CHMOD} -R ${BINMODE} ${STAGEDIR}${_APPDIR}/erts-*/bin
	${CHMOD} -R ${BINMODE} ${STAGEDIR}${_APPDIR}/lib/*/priv/*.so
	${CHMOD} -R ${BINMODE} ${STAGEDIR}${_APPDIR}/lib/couch_quickjs-*/priv/couchjs_*
	${CHMOD} -R ${BINMODE} ${STAGEDIR}${_APPDIR}/lib/os_mon-*/priv/bin
# fauxton UI is a required component
	(cd ${WRKSRC}/share/www && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

post-install:
	${MKDIR} ${STAGEDIR}${_DBDIR} \
		${STAGEDIR}${_LOGDIR} \
		${STAGEDIR}${_RUNDIR}

post-install-DOCS-on:
	(cd ${WRKSRC}/share/docs/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/docs)

.include <bsd.port.mk>
