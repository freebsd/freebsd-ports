# $FreeBSD$

PORTNAME=	riak
PORTVERSION=	1.4.2
CATEGORIES=	databases
MASTER_SITES=	http://s3.amazonaws.com/downloads.basho.com/riak/${PORTVERSION:R}/${PORTVERSION}/ \
		http://downloads.basho.com.s3.amazonaws.com/riak/${PORTVERSION:R}/${PORTVERSION}/

MAINTAINER=	ports@robakdesign.com
COMMENT=	Riak is an open source, distributed database

BUILD_DEPENDS=	${LOCALBASE}/lib/erlang15/bin/erlc:${PORTSDIR}/lang/erlang-runtime15

USES=		gmake
USE_RC_SUBR=	riak

PLIST=		${WRKDIR}/pkg-plist
PLIST_SUB+=	RIAK_LOGDIR=${RIAK_LOGDIR} \
		RIAK_DBDIR=${RIAK_DBDIR} \
		RIAK_CONFDIR=${RIAK_CONFDIR} \
		RIAK_HOMEDIR=${RIAK_HOMEDIR}

USERS=		riak
GROUPS=		riak

RIAK_CONFDIR?=	${PREFIX}/etc/${PORTNAME}
RIAK_LOGDIR?=	/var/log/${PORTNAME}
RIAK_DBDIR?=	/var/db/${PORTNAME}
RIAK_LIBDIR?=	${PREFIX}/lib/${PORTNAME}/lib
RIAK_HOMEDIR?=	${PREFIX}/lib/${PORTNAME}

MAN1=		riak.1 riak-admin.1 riak-debug.1 search-cmd.1
MANCOMPRESSED=	yes

ALL_TARGET=	rel
MAKE_JOBS_UNSAFE=yes
MAKE_ENV=	PATH=${LOCALBASE}/lib/erlang15/bin:${PATH}
NO_STAGE=	yes

.include <bsd.port.pre.mk>

pre-install:
	${RM} -f ${PLIST}
	${CAT} ${PKGDIR}/pkg-plist >> ${PLIST}
	cd ${WRKSRC}/rel/${PORTNAME}; ${FIND} releases -type f \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn | ${SED} -e 's/^/lib\//' \
		| ${AWK} '{print "lib/riak/"$$2 }' >> ${PLIST}
	cd ${WRKSRC}/rel/${PORTNAME}; ${FIND} erts-* -type f \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn  \
		| ${AWK} '{print "lib/riak/"$$2 }' >> ${PLIST}
	cd ${WRKSRC}/rel; ${FIND} ${PORTNAME}/lib -type f \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn | ${SED} -e 's/^/lib\//' \
		| ${AWK} '{print "lib/"$$2 }' >> ${PLIST}
	cd ${WRKSRC}/rel/${PORTNAME}; ${FIND} releases -type d \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn | ${SED} -e 's/^/lib\//' \
		| ${AWK} '{print "lib/riak/"$$2 }' | ${SED} -e "s/^/@dirrm\ /" >> ${PLIST}
	cd ${WRKSRC}/rel/${PORTNAME}; ${FIND} erts-* -type d \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn | ${SED} -e 's/^/lib\//' \
		| ${AWK} '{print "lib/riak/"$$2 }' | ${SED} -e "s/^/@dirrm\ /" >> ${PLIST}
	cd ${WRKSRC}/rel; ${FIND} ${PORTNAME}/lib -type d \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn | ${SED} -e 's/^/lib\//' \
		| ${AWK} '{print "lib/"$$2 }' | ${SED} -e "s/^/@dirrm\ /" >> ${PLIST}
	${ECHO} "@dirrm lib/riak" >> ${PLIST}
	${ECHO} "@cwd /" >> ${PLIST}
	${ECHO} "@dirrmtry %%RIAK_DBDIR%%" >> ${PLIST}
	${ECHO} "@dirrmtry %%RIAK_LOGDIR%%" >> ${PLIST}

do-install:
.for d in ${RIAK_CONFDIR} ${RIAK_LOGDIR} ${RIAK_DBDIR} ${RIAK_LIBDIR} ${RIAK_HOMEDIR}
	[ -d ${d} ] || ${MKDIR} ${d} && ${CHOWN} ${USERS}:${GROUPS} ${d}
.endfor
	${INSTALL_DATA} ${WRKSRC}/rel/riak/etc/vm.args ${RIAK_CONFDIR}/vm.args.sample
	${INSTALL_DATA} ${WRKSRC}/rel/riak/etc/app.config ${RIAK_CONFDIR}/app.config.sample
	${INSTALL_DATA} ${WRKSRC}/rel/riak/etc/cert.pem ${RIAK_CONFDIR}/cert.pem.sample
	${INSTALL_DATA} ${WRKSRC}/rel/riak/etc/key.pem ${RIAK_CONFDIR}/key.pem.sample
	(cd ${WRKSRC}/rel/riak/lib/ && ${COPYTREE_BIN} . ${RIAK_LIBDIR})
	(cd ${WRKSRC}/rel/riak/bin/ && ${COPYTREE_BIN} . ${PREFIX}/sbin/)
	(cd ${WRKSRC}/rel/riak/lib/basho-patches && ${COPYTREE_SHARE} . ${RIAK_LIBDIR}/basho-patches)
	(cd ${WRKSRC}/rel/riak/releases && ${COPYTREE_SHARE} . ${RIAK_HOMEDIR}/releases)
	${CP} -R ${WRKSRC}/rel/riak/erts-* ${RIAK_HOMEDIR}
	${CHOWN} -R ${USERS}:${GROUPS} ${PREFIX}/lib/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/doc/man/man1/riak.1.gz ${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/man/man1/riak-admin.1.gz ${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/man/man1/riak-debug.1.gz ${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/man/man1/search-cmd.1.gz ${MANPREFIX}/man/man1/

post-install:
	@if [ ! -f ${RIAK_CONFDIR}/vm.args ]; then \
		${CP} -p ${RIAK_CONFDIR}/vm.args.sample ${RIAK_CONFDIR}/vm.args; \
	fi
	@if [ ! -f ${RIAK_CONFDIR}/app.config ]; then \
		${CP} -p ${RIAK_CONFDIR}/app.config.sample ${RIAK_CONFDIR}/app.config; \
	fi
	@if [ ! -f ${RIAK_CONFDIR}/cert.pem ]; then \
		${CP} -p ${RIAK_CONFDIR}/cert.pem.sample ${RIAK_CONFDIR}/cert.pem; \
	fi
	@if [ ! -f ${RIAK_CONFDIR}/key.pem ]; then \
		${CP} -p ${RIAK_CONFDIR}/key.pem.sample ${RIAK_CONFDIR}/key.pem; \
	fi

.include <bsd.port.post.mk>
