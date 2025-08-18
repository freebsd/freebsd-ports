PORTNAME=	act_runner
DISTVERSIONPREFIX=	v
DISTVERSION=	9.1.0
CATEGORIES=	devel
PKGNAMEPREFIX=	forgejo-

PATCH_SITES=	https://code.forgejo.org/forgejo/runner/commit/
PATCHFILES=	34731a41be456d5b6328d8c118ba8e0b6c6a226b.diff:-p1

MAINTAINER=	daniel@morante.net
COMMENT=	Act runner is a runner for Forgejo based on the Gitea Act runner
WWW=		https://code.forgejo.org/forgejo/runner

LICENSE=	MIT APACHE20
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/act/container/DOCKER_LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

USES=	go:modules
USE_RC_SUBR=	${PORTNAME}

GO_MODULE=	code.forgejo.org/forgejo/runner/v9
GO_BUILDFLAGS=	-ldflags "${LD_FLAG_STRING}"

LD_FLAG_STRING=	-s ${LD_FLAG_X_PREFIX}.version=${DISTVERSION}
LD_FLAG_X_PREFIX=	-X ${GO_MODULE}/internal/pkg/ver

DATADIR=	/var/db/${PORTNAME}

USERS=	${ACT_RUNNER_USER}
GROUPS=	${ACT_RUNNER_GROUP}

ACT_RUNNER_USER?=	${PORTNAME}
ACT_RUNNER_GROUP?=	${PORTNAME}

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/internal/pkg/config/config.example.yaml ${STAGEDIR}${ETCDIR}/act_runner.conf.sample

.include <bsd.port.mk>
