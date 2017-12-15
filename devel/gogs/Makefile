# $FreeBSD$

PORTNAME=	gogs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.34
CATEGORIES=	devel www

MAINTAINER=	dg@syrec.org
COMMENT=	Painless self-hosted Git service

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go
RUN_DEPENDS=	git:devel/git

USE_GITHUB=	yes
GH_ACCOUNT=	gogits
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

USERS=		gogs
GROUPS=		gogs

GOGS_DBDIR?=	/var/db/gogs
GOGS_LOGDIR?=	/var/log/gogs
PORTNAME_FANCY=	Gogs

SUB_FILES=	gogs \
		gogs-service \
		gogs-rm-data \
		pkg-message
SUB_LIST=	PREFIX=${PREFIX} \
		PORTNAME=${PORTNAME} \
		PORTNAME_FANCY=${PORTNAME_FANCY} \
		GOGS_USER=${USERS} \
		GOGS_DBDIR=${GOGS_DBDIR} \
		GOGS_LOGDIR=${GOGS_LOGDIR}
PLIST_SUB=	GOGS_USER=${USERS} \
		GOGS_GROUP=${GROUPS} \
		GOGS_DBDIR=${GOGS_DBDIR} \
		GOGS_LOGDIR=${GOGS_LOGDIR}

PORTDOCS=	README.md

post-patch:
	@${REINPLACE_CMD} -i '' \
		-e 's|^ROOT =$$|ROOT = ${GOGS_DBDIR}/repositories|' \
		-e 's|^RUN_USER = git$$|RUN_USER = ${USERS}|' \
		-e 's|^DB_TYPE = mysql$$|DB_TYPE = sqlite3|' \
		${WRKSRC}/conf/app.ini

do-build:
	@(cd ${WRKSRC}/${GH_SUBDIR} && \
		${SETENV} GOPATH=${WRKSRC} go build -tags "sqlite pam cert" -p ${MAKE_JOBS_NUMBER} -o ${PORTNAME})

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/
	${INSTALL_SCRIPT} ${WRKDIR}/gogs ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKDIR}/gogs-rm-data ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKDIR}/gogs-service ${STAGEDIR}${PREFIX}/etc/rc.d/gogs
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "conf public templates" ${STAGEDIR}${PREFIX}/libexec/${PORTNAME})
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/custom/conf
	${INSTALL_DATA} ${WRKSRC}/conf/app.ini ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/custom/conf/
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/custom/https
	@${MKDIR} ${STAGEDIR}${GOGS_DBDIR}/data ${STAGEDIR}${GOGS_DBDIR}/repositories ${STAGEDIR}${GOGS_DBDIR}/home
	@${LN} -sf ${GOGS_DBDIR}/data ${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}/data
	@${MKDIR} ${STAGEDIR}${GOGS_LOGDIR}
	@${LN} -sf ${GOGS_LOGDIR} ${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}/log
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
