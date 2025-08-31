PORTNAME=	act_runner
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.13
CATEGORIES=	devel
PKGNAMEPREFIX=	gitea-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Act runner is a runner for Gitea based on Gitea fork of act
WWW=		https://gitea.com/gitea/act_runner

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	go:modules
USE_RC_SUBR=	${PORTNAME}

GO_MODULE=	gitea.com/gitea/act_runner

DATADIR=	/var/db/${PORTNAME}

USERS=	${ACT_RUNNER_USER}
GROUPS=	${ACT_RUNNER_GROUP}

ACT_RUNNER_USER?=	${PORTNAME}
ACT_RUNNER_GROUP?=	${PORTNAME}

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/internal/pkg/config/config.example.yaml ${STAGEDIR}${ETCDIR}/act_runner.conf.sample

.include <bsd.port.mk>
