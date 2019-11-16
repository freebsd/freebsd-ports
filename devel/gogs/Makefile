# $FreeBSD$

PORTNAME=	gogs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.91
PORTREVISION=	1
CATEGORIES=	devel www

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Painless self-hosted Git service

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git \
		bash:shells/bash

USES=		go

GO_BUILDFLAGS=	-tags "sqlite pam cert"

USE_GITHUB=	yes
GH_ACCOUNT=	gogs
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

GO_TARGET=	:${PREFIX}/libexec/${PORTNAME}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

USERS=		git
GROUPS=		git

GOGS_DBDIR?=	/var/db/gogs
GOGS_LOGDIR?=	/var/log/gogs
PORTNAME_FANCY=	Gogs

SUB_FILES=	gogs \
		gogs-service \
		gogs-rm-data \
		pkg-message
SUB_LIST=	PORTNAME=${PORTNAME} \
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
	@${REINPLACE_CMD} \
		-e '/^# \!\!\!/d' \
		-e 's|^RUN_USER = git$$|RUN_USER = ${USERS}|' \
		-e 's|^RUN_MODE = dev$$|RUN_MODE = prod|' \
		-e 's|^ROOT =$$|ROOT = ${GOGS_DBDIR}/repositories|' \
		-e 's|^ROOT_PATH =$$|ROOT_PATH = ${GOGS_LOGDIR}|' \
		-e 's|^DB_TYPE = mysql$$|DB_TYPE = sqlite3|' \
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

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
