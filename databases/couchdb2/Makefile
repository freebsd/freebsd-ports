# Created by: Dave Cottlehuber <dch@FreeBSD.org>
# $FreeBSD$

PORTNAME=	couchdb2
DISTVERSION=	2.3.1
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	APACHE/couchdb/source/${DISTVERSION}
DISTNAME=	apache-couchdb-${DISTVERSION}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	JSON document database with HTTP API and scalable multi-master sync

LICENSE=	APACHE20 BSD3CLAUSE ISCL WTFPL OFL11
LICENSE_COMB=	multi

BUILD_DEPENDS=	rebar:devel/rebar \
		erlang-runtime21>=21.3:lang/erlang-runtime21
LIB_DEPENDS=	libicudata.so:devel/icu \
		libmozjs185.so:lang/spidermonkey185
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		erlang-runtime21>=21.3:lang/erlang-runtime21

USES=		cpe gmake libtool ncurses python:run shebangfix
USE_RC_SUBR=	couchdb2

CPE_VENDOR=	apache
SHEBANG_FILES=	rel/overlay/bin/couchup

USERS=		couchdb
GROUPS=		couchdb

SUB_FILES=	pkg-message
SUB_LIST=	APPDIR=${APPDIR} \
		ERL_PATH=${LOCALBASE}/lib/erlang21/bin/erl \
		PORTNAME=${PORTNAME} \
		RELDIR=${RELDIR}
PLIST_SUB=	VERSION=${DISTVERSION}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--skip-deps --user ${USERS} --disable-docs --disable-fauxton

ALL_TARGET=	release

MAKE_ENV=	PATH=${LOCALBASE}/lib/erlang21/bin:${PATH}

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DBDIR?=		/var/db/${PORTNAME}
LOGFILE?=	/var/log/${PORTNAME}/couch.log
APPDIR=		${LOCALBASE}/libexec/${PORTNAME}
RELDIR=		${APPDIR}/releases/${DISTVERSION}

post-patch:
	@${REINPLACE_CMD} \
	    -e 's,%%APPDIR%%,${APPDIR},g' \
	    -e 's,%%DATADIR%%,${DATADIR},g' \
	    -e 's,%%DBDIR%%,${DBDIR},g' \
	    -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
	    -e 's,%%PORTNAME%%,${PORTNAME},g' \
	    -e 's,%%WWWDIR%%,${WWWDIR},g' \
	    -e 's,\$COUCHDB_USER,${USERS},g' \
	    -e 's,\$LOG_FILE,${LOGFILE},g' \
	    ${WRKSRC}/configure

pre-install:
	# relocate user-modifiable runtime configs to match hier(7)
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/rel/couchdb/etc/local.ini \
		${STAGEDIR}${ETCDIR}/local.ini.sample
	${INSTALL_DATA} ${WRKSRC}/rel/couchdb/etc/vm.args \
		${STAGEDIR}${ETCDIR}/vm.args.sample
	${INSTALL_MAN} ${WRKSRC}/share/docs/man/apachecouchdb.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	# prune build artefacts and surplus headers
	@${FIND} -E ${WRKSRC} -type f \
		-regex '.*\.(a|buildinfo|c|cc|cmd|d|h|o|orig|1)' -delete
	# remove runtime dirs and files that were moved to match hier(7)
	@${RM} -r ${WRKSRC}/rel/couchdb/var \
		${WRKSRC}/rel/couchdb/etc/*.d \
		${WRKSRC}/rel/couchdb/etc/local.ini \
		${WRKSRC}/rel/couchdb/etc/vm.args \
		${WRKSRC}/rel/couchdb/releases/*/vm.args \
		${WRKSRC}/rel/couchdb/lib/couch-*/priv/couchjs \
		${WRKSRC}/share/server
	@${CP} ${WRKSRC}/src/docs/images/favicon.ico ${WRKSRC}/share/www/
	(cd ${WRKSRC}/rel/couchdb && ${COPYTREE_SHARE} . ${STAGEDIR}${APPDIR})

post-install:
	@${FIND} -E ${STAGEDIR} -type f \
		\( -name couchjs -o -name *.so \) \
		-exec ${STRIP_CMD} {} +
	@${MKDIR} \
		${STAGEDIR}/var/db/${PORTNAME} \
		${STAGEDIR}/var/log/${PORTNAME}
	# fauxton UI is a required component
	(cd ${WRKSRC}/share/www && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

post-install-DOCS-on:
	(cd ${WRKSRC}/share/docs/html && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/docs)

.include <bsd.port.mk>
