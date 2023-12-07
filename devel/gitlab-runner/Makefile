PORTNAME=	gitlab-runner
DISTVERSION=	16.6.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
MASTER_SITES=	https://gitlab-runner-downloads.s3.amazonaws.com/master/docker/:dockerx64 \
		https://gitlab-runner-downloads.s3.amazonaws.com/master/docker/:dockerarm
DISTFILES=	prebuilt-x86_64.tar.xz:dockerx64 \
		prebuilt-arm.tar.xz:dockerarm

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Official GitLab Runner written in Go
WWW=		https://gitlab.com/gitlab-org/gitlab-runner

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go-bindata:devel/go-bindata
RUN_DEPENDS=	bash:shells/bash \
		ca_root_nss>=0:security/ca_root_nss \
		git:devel/git

USES=		go:modules
GO_MODULE=	gitlab.com/gitlab-org/gitlab-runner

_BUILD_DATE=	$$(date -u +%Y-%m-%dT%H:%M:%S%z)
GO_BUILDFLAGS= -ldflags=" \
		-X gitlab.com/gitlab-org/gitlab-runner/commands.ROOTCONFIGDIR=${ETCDIR} \
		-X gitlab.com/gitlab-org/gitlab-runner/common.VERSION=${PORTVERSION} \
		-X gitlab.com/gitlab-org/gitlab-runner/common.REVISION=${DISTVERSION} \
		-X gitlab.com/gitlab-org/gitlab-runner/common.BUILT=${_BUILD_DATE} \
		-X gitlab.com/gitlab-org/gitlab-runner/common.BRANCH=${GITBRANCH} \
		-s -w"
USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
GITBRANCH=	16-6-stable

# for go dependencies
# Gitlab hosts there dependencies on their own platform and not on go-proxy
# so we download the required go.mod file from gitlab
# lines are taken from go.mk
# ---------------------------
MASTER_SITES+=	https://gitlab.com/gitlab-org/gitlab-runner/-/raw/v${DISTVERSION}/
DISTFILES+=	go.mod
EXTRACT_ONLY+=	${DISTFILES:N*.mod\:*:N*.mod:C/:.*//:Nprebuilt*:}
# ---------------------------

PLIST_FILES=	bin/gitlab-runner

USE_RC_SUBR=	gitlab_runner

USERS=		gitlab-runner
GROUPS=		gitlab-runner

post-patch:
	@${MKDIR} ${WRKSRC}/out/docker/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/prebuilt-x86_64.tar.xz ${WRKSRC}/out/docker/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/prebuilt-arm.tar.xz ${WRKSRC}/out/docker/

pre-build:
	@cd ${WRKSRC} && go-bindata \
		-pkg docker \
		-nocompress \
		-nomemcopy \
		-nometadata \
		-prefix out/docker/ \
		-o executors/docker/bindata.go \
		out/docker/prebuilt-x86_64.tar.xz \
		out/docker/prebuilt-arm.tar.xz

.include <bsd.port.mk>
