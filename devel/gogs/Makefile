PORTNAME=	gogs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.3
PORTREVISION=	2
CATEGORIES=	devel www

MAINTAINER=	me@svmhdvn.name
COMMENT=	Painless self-hosted Git service
WWW=		https://gogs.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go-bindata:devel/go-bindata
RUN_DEPENDS=	git:devel/git \
		bash:shells/bash

USES=		cpe go:modules

GO_MODULE=	gogs.io/gogs
GO_TARGET=	:${PREFIX}/libexec/${PORTNAME}/${PORTNAME}
GO_BUILDFLAGS=	-tags "sqlite pam cert"

SUB_FILES=	gogs \
		gogs-service \
		gogs-rm-data \
		pkg-message
SUB_LIST=	PORTNAME=${PORTNAME} \
		PORTNAME_FANCY=${PORTNAME_FANCY} \
		GOGS_USER=${USERS} \
		GOGS_DBDIR=${GOGS_DBDIR} \
		GOGS_LOGDIR=${GOGS_LOGDIR}

USERS=		git
GROUPS=		git

PLIST_SUB=	GOGS_USER=${USERS} \
		GOGS_GROUP=${GROUPS} \
		GOGS_DBDIR=${GOGS_DBDIR} \
		GOGS_LOGDIR=${GOGS_LOGDIR}

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

GOGS_DBDIR?=	/var/db/gogs
GOGS_LOGDIR?=	/var/log/gogs
PORTNAME_FANCY=	Gogs

post-patch:
	@${REINPLACE_CMD} \
		-e '/^# \!\!\!/d' \
		-e 's|^RUN_USER = git$$|RUN_USER = ${USERS}|' \
		-e 's|^RUN_MODE = dev$$|RUN_MODE = prod|' \
		-e 's|^ROOT =$$|ROOT = ${GOGS_DBDIR}/repositories|' \
		-e 's|^ROOT_PATH =$$|ROOT_PATH = ${GOGS_LOGDIR}|' \
		-e 's|^TYPE = postgres$$|DB_TYPE = sqlite3|' \
		${WRKSRC}/conf/app.ini

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/gogs ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKDIR}/gogs-rm-data ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKDIR}/gogs-service ${STAGEDIR}${PREFIX}/etc/rc.d/gogs
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "conf public templates" ${STAGEDIR}${PREFIX}/libexec/${PORTNAME})
	@${MKDIR} ${STAGEDIR}${ETCDIR}/conf
	@${MKDIR} ${STAGEDIR}${ETCDIR}/https
	${INSTALL_DATA} ${WRKSRC}/conf/app.ini ${STAGEDIR}${ETCDIR}/conf/app.ini.sample
	@${RLN} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/custom
	@${MKDIR} ${STAGEDIR}${GOGS_DBDIR}/data ${STAGEDIR}${GOGS_DBDIR}/repositories
	@${LN} -sf ${GOGS_DBDIR}/data ${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}/data
	@${MKDIR} ${STAGEDIR}${GOGS_LOGDIR}
	@${LN} -sf ${GOGS_LOGDIR} ${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}/log

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
