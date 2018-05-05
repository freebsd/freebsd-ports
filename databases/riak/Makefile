# $FreeBSD$

PORTNAME=	riak
PORTVERSION=	1.4.12
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://s3.amazonaws.com/downloads.basho.com/riak/${PORTVERSION:R}/${PORTVERSION}/ \
		http://downloads.basho.com.s3.amazonaws.com/riak/${PORTVERSION:R}/${PORTVERSION}/

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Open source, distributed, noSQL database

LICENSE=	APACHE20

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2018-06-06

BUILD_DEPENDS=	${LOCALBASE}/lib/erlang15/bin/erlc:lang/erlang-runtime15

USES=		gmake readline shebangfix
SHEBANG_FILES=	deps/eper/priv/bin/dtop \
		deps/eper/priv/bin/gperf \
		deps/eper/priv/bin/ntop \
		deps/eper/priv/bin/redbug \
		deps/eper/priv/bin/sherk
USE_RC_SUBR=	riak

PLIST=		${WRKDIR}/pkg-plist
PLIST_SUB+=	GROUPS=${GROUPS} \
		RIAK_CONFDIR=${RIAK_CONFDIR} \
		RIAK_DBDIR=${RIAK_DBDIR} \
		RIAK_HOMEDIR=${RIAK_HOMEDIR} \
		RIAK_LIBDIR=${RIAK_LIBDIR} \
		RIAK_LOGDIR=${RIAK_LOGDIR} \
		USERS=${USERS}

USERS=		riak
GROUPS=		riak

RIAK_CONFDIR?=	${PREFIX}/etc/${PORTNAME}
RIAK_LOGDIR?=	/var/log/${PORTNAME}
RIAK_DBDIR?=	/var/db/${PORTNAME}
RIAK_LIBDIR?=	${PREFIX}/lib/${PORTNAME}/lib
RIAK_HOMEDIR?=	${PREFIX}/lib/${PORTNAME}

ALL_TARGET=	rel
MAKE_JOBS_UNSAFE=yes
MAKE_ENV=	PATH=${LOCALBASE}/lib/erlang15/bin:${PATH}

BROKEN_aarch64=		Does not compile: error: Unknown CPU architecture
BROKEN_powerpc64=	Does not compile: error: Unknown CPU architecture
BROKEN_sparc64=		Does not compile: Please implement AtomicPointer for this platform

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/rel/vars.config

pre-install:
	${RM} ${PLIST}
	${CAT} ${PKGDIR}/pkg-plist >> ${PLIST}
	(cd ${WRKSRC}/rel/${PORTNAME}; ${FIND} releases -type f \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn | ${SED} -e 's/^/lib\//' \
		| ${AWK} '{print "lib/riak/"$$2 }' >> ${PLIST})
	(cd ${WRKSRC}/rel/${PORTNAME}; ${FIND} erts-* -type f \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn  \
		| ${AWK} '{print "lib/riak/"$$2 }' >> ${PLIST})
	(cd ${WRKSRC}/rel; ${FIND} ${PORTNAME}/lib -type f \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn | ${SED} -e 's/^/lib\//' \
		| ${AWK} '{print "lib/"$$2 }' >> ${PLIST})
	${ECHO} "@owner" >> ${PLIST}
	${ECHO} "@group" >> ${PLIST}

do-install:
.for d in ${RIAK_CONFDIR} ${RIAK_LOGDIR} ${RIAK_DBDIR} ${RIAK_LIBDIR} ${RIAK_HOMEDIR}
	${MKDIR} ${STAGEDIR}${d}
.endfor
	${INSTALL_DATA} ${WRKSRC}/rel/riak/etc/vm.args ${STAGEDIR}${RIAK_CONFDIR}/vm.args.sample
	${INSTALL_DATA} ${WRKSRC}/rel/riak/etc/app.config ${STAGEDIR}${RIAK_CONFDIR}/app.config.sample
	${INSTALL_DATA} ${WRKSRC}/rel/riak/etc/cert.pem ${STAGEDIR}${RIAK_CONFDIR}/cert.pem.sample
	${INSTALL_DATA} ${WRKSRC}/rel/riak/etc/key.pem ${STAGEDIR}${RIAK_CONFDIR}/key.pem.sample
	(cd ${WRKSRC}/rel/riak/lib/ && ${COPYTREE_BIN} . ${STAGEDIR}${RIAK_LIBDIR})
	(cd ${WRKSRC}/rel/riak/bin/ && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/sbin/)
	(cd ${WRKSRC}/rel/riak/lib/basho-patches && ${COPYTREE_SHARE} . ${STAGEDIR}${RIAK_LIBDIR}/basho-patches)
	(cd ${WRKSRC}/rel/riak/releases && ${COPYTREE_SHARE} . ${STAGEDIR}${RIAK_HOMEDIR}/releases)
	${CP} -R ${WRKSRC}/rel/riak/erts-* ${STAGEDIR}${RIAK_HOMEDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/man/man1/riak.1.gz ${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/man/man1/riak-admin.1.gz ${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/man/man1/riak-debug.1.gz ${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/man/man1/search-cmd.1.gz ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.post.mk>
