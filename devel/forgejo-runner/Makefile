PORTNAME=	act_runner
DISTVERSIONPREFIX=	v
DISTVERSION=	12.5.0
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	forgejo-

MAINTAINER=	daniel@morante.net
COMMENT=	Act runner is a runner for Forgejo based on the Gitea Act runner
WWW=		https://code.forgejo.org/forgejo/runner

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/act/container/DOCKER_LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

USES=		go:1.25+,modules
USE_RC_SUBR=	${PORTNAME}

GO_MODULE=	code.forgejo.org/forgejo/runner/v${DISTVERSION:R:R}
GO_BUILDFLAGS=	-ldflags "${LD_FLAG_STRING}"

LD_FLAG_STRING=		-s ${LD_FLAG_X_PREFIX}.version=${DISTVERSION}
LD_FLAG_X_PREFIX=	-X ${GO_MODULE}/internal/pkg/ver

DATADIR=	/var/db/${PORTNAME}
LOGDIR=		/var/log/${PORTNAME}
PIDDIR=		/var/run/${PORTNAME}
SUB_LIST=	ACT_RUNNER_USER=${ACT_RUNNER_USER} \
		LOGDIR=${LOGDIR} \
		PIDDIR=${PIDDIR}

ACT_RUNNER_USER?=	${PORTNAME}
ACT_RUNNER_GROUP?=	${PORTNAME}
.if ${ACT_RUNNER_USER} == ${PORTNAME}
USERS=		${ACT_RUNNER_USER}
.endif
.if ${ACT_RUNNER_GROUP} == ${PORTNAME}
GROUPS=		${ACT_RUNNER_GROUP}
.endif

PLIST_SUB=	ACT_RUNNER_GROUP=${ACT_RUNNER_GROUP} \
		ACT_RUNNER_USER=${ACT_RUNNER_USER} \
		LOGDIR=${LOGDIR} \
		PIDDIR=${PIDDIR}

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR} \
		 ${STAGEDIR}${ETCDIR} \
		 ${STAGEDIR}${LOGDIR} \
		 ${STAGEDIR}${PIDDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/internal/pkg/config/config.example.yaml \
		${STAGEDIR}${ETCDIR}/act_runner.conf.sample

.include <bsd.port.mk>
