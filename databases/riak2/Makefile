# $FreeBSD$

PORTNAME=	riak2
PORTVERSION=	2.1.1
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://s3.amazonaws.com/downloads.basho.com/riak/${PORTVERSION:R}/${PORTVERSION}/ \
	http://downloads.basho.com.s3.amazonaws.com/riak/${PORTVERSION:R}/${PORTVERSION}/ \
	http://s3.amazonaws.com/files.basho.com/solr/:solr \
	http://s3.amazonaws.com/files.basho.com/yokozuna/:yokozuna
DISTNAME=	riak-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
	solr-4.7.0-yz-1.tgz:solr \
	yokozuna-1.jar:yokozuna \
	yz_monitor-1.jar:yokozuna
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} solr-4.7.0-yz-1.tgz

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Riak is an open source, distributed, noSQL database

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/lib/riak-erlang/bin/erlc:lang/erlang-riak

USES=		gmake readline shebangfix
SHEBANG_FILES=	deps/eper/priv/bin/* \
		../solr-4.7.0-yz-1/example/etc/create-solrtest.keystore.sh
USE_RC_SUBR=	riak
USE_GCC=	yes

BROKEN_i386=		Does not build
BROKEN_powerpc64=	Does not build
BROKEN_sparc64=		Does not build: Please implement AtomicPointer for this platform

USERS=		riak
GROUPS=		riak

RIAK_CONFDIR?=	${PREFIX}/etc/riak
RIAK_DBDIR?=	/var/db/riak
RIAK_HOMEDIR?=	${PREFIX}/lib/riak
RIAK_LIBDIR?=	${PREFIX}/lib/riak/lib
RIAK_LOGDIR?=	/var/log/riak

PLIST_SUB+=	RIAK_CONFDIR=${RIAK_CONFDIR} \
	RIAK_DBDIR=${RIAK_DBDIR} \
	RIAK_HOMEDIR=${RIAK_HOMEDIR} \
	RIAK_LIBDIR=${RIAK_LIBDIR} \
	RIAK_LOGDIR=${RIAK_LOGDIR} \
	USERS=${USERS} \
	GROUPS=${GROUPS}

ALL_TARGET=	rel
MAKE_JOBS_UNSAFE=yes
MAKE_ENV=	PATH=${LOCALBASE}/lib/riak-erlang/bin:${PATH}

post-patch:
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/rel/vars.config
	@${REINPLACE_CMD} -e 's|%%BUILD_DIR%%|${WRKDIR}|g' \
		-e 's|%%DISTDIR%%|${DISTDIR}|g' \
		-e 's|%%YOKOZUNA%%|${WRKSRC}/deps/yokozuna|g' \
		${WRKSRC}/deps/yokozuna/tools/grab-solr.sh

do-install:
	${MKDIR} ${STAGEDIR}${RIAK_CONFDIR}
	${MKDIR} ${STAGEDIR}${RIAK_DBDIR}
	${MKDIR} ${STAGEDIR}${RIAK_LOGDIR}
	${INSTALL_DATA} ${WRKSRC}/rel/riak/etc/riak.conf ${STAGEDIR}${RIAK_CONFDIR}/riak.conf.sample
	${INSTALL_DATA} ${WRKSRC}/rel/riak/etc/solr-log4j.properties ${STAGEDIR}${RIAK_CONFDIR}/solr-log4j.properties.sample
	(cd ${WRKSRC}/rel/riak/lib/ && ${COPYTREE_BIN} . ${STAGEDIR}${RIAK_LIBDIR})
	(cd ${WRKSRC}/rel/riak/bin/ && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/sbin/)
	(cd ${WRKSRC}/rel/riak/lib/basho-patches && ${COPYTREE_SHARE} . ${STAGEDIR}${RIAK_LIBDIR}/basho-patches)
	(cd ${WRKSRC}/rel/riak/releases && ${COPYTREE_SHARE} . ${STAGEDIR}${RIAK_HOMEDIR}/releases)
	${CP} -R ${WRKSRC}/rel/riak/erts-* ${STAGEDIR}${RIAK_HOMEDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/man/man1/riak.1.gz ${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/man/man1/riak-admin.1.gz ${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/man/man1/riak-debug.1.gz ${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/man/man1/search-cmd.1.gz ${STAGEDIR}${MANPREFIX}/man/man1/
	#@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/riak/lib/bitcask-1.7.0/priv/bitcask.so
	#@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/riak/lib/erlang_js-1.3.0-0-g07467d8/priv/erlang_js_drv.so
	#@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/riak/lib/syslog-1.0.2/priv/syslog_drv.so
	#@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/riak/lib/canola-2.0.0-0-g9bdfee8/priv/canola-port
	#@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/riak/lib/sext-1.1p3-0-g846b9cc/priv/sext.so

post-install:
	(cd ${STAGEDIR}${RIAK_HOMEDIR}; ${FIND} releases -type f \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn | ${SED} -e 's/^/lib\//' \
		| ${AWK} '{print "lib/riak/"$$2 }' >> ${TMPPLIST})
	(cd ${STAGEDIR}${RIAK_HOMEDIR}; ${FIND} erts-* -type f \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn  \
		| ${AWK} '{print "lib/riak/"$$2 }' >> ${TMPPLIST})
	(cd ${STAGEDIR}${RIAK_LIBDIR}; ${FIND} . -type f \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn | ${SED} -e 's/^/lib\//' \
		| ${AWK} '{print "lib/riak/lib/"$$2 }' >> ${TMPPLIST})
	(cd ${STAGEDIR}${RIAK_LIBDIR}; ${FIND} . -type d -empty \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn | ${SED} -e 's/^/lib\//' \
		| ${AWK} '{print "@dir lib/riak/lib/"$$2 }' >> ${TMPPLIST})
	${ECHO} "@owner" >> ${TMPPLIST}
	${ECHO} "@group" >> ${TMPPLIST}

.include <bsd.port.mk>
