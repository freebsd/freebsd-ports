PORTNAME=	gitlab-runner
DISTVERSIONPREFIX=	v
DISTVERSION=	19.3.2
CATEGORIES=	devel
MASTER_SITES=	https://gitlab-runner-downloads.s3.amazonaws.com/master/docker/:dockerx64 \
		https://gitlab-runner-downloads.s3.amazonaws.com/master/docker/:dockerarm
DISTFILES=	prebuilt-x86_64.tar.xz:dockerx64 \
		prebuilt-arm.tar.xz:dockerarm

#PATCH_SITES=	https://gitlab.com/gitlab-org/gitlab-runner/-/merge_requests/
#PATCHFILES+=	5966.patch:-p1 # https://gitlab.com/gitlab-org/gitlab-runner/-/merge_requests/5966, Fix bash shell cleanup to support variable expansion in paths
#PATCH_SITES=	https://gitlab.com/mfechner/gitlab-runner/-/commit/
#PATCHFILES+=	2f12af03ccd5fe875d583ddc8b976329b635fd22.patch:-p1

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Official GitLab Runner written in Go
WWW=		https://gitlab.com/gitlab-org/gitlab-runner

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go-bindata:devel/go-bindata
RUN_DEPENDS=	bash:shells/bash \
		ca_root_nss>=0:security/ca_root_nss \
		git:devel/git \
		gitlab-analyzers-secrets>=0:security/gitlab-analyzers-secrets

USES=		cpe go:modules
CPE_PRODUCT=	runner
CPE_VENDOR=	gitlab
USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
USE_RC_SUBR=	gitlab_runner
GO_MOD_DIST=	gitlab

GITBRANCH=	19-3-stable
GO_MODULE=	gitlab.com/gitlab-org/gitlab-runner

_BUILD_DATE=	$$(date -u +%Y-%m-%dT%H:%M:%S%z)
GO_BUILDFLAGS= -ldflags=" \
		-X gitlab.com/gitlab-org/gitlab-runner/commands.ROOTCONFIGDIR=${ETCDIR} \
		-X gitlab.com/gitlab-org/gitlab-runner/common.VERSION=${PORTVERSION} \
		-X gitlab.com/gitlab-org/gitlab-runner/common.REVISION=${DISTVERSION} \
		-X gitlab.com/gitlab-org/gitlab-runner/common.BUILT=${_BUILD_DATE} \
		-X gitlab.com/gitlab-org/gitlab-runner/common.BRANCH=${GITBRANCH} \
		-s -w"

# for go dependencies
# Gitlab hosts there dependencies on their own platform and not on go-proxy
# so we download the required go.mod file from gitlab
# lines are taken from go.mk
# ---------------------------
#MASTER_SITES+=	https://gitlab.com/gitlab-org/gitlab-runner/-/raw/v${DISTVERSION}/
#DISTFILES+=	go.mod
EXTRACT_ONLY+=	${DISTFILES:N*.mod\:*:N*.mod:C/:.*//:Nprebuilt*:}
# ---------------------------

USERS=		gitlab-runner
GROUPS=		gitlab-runner

PLIST_FILES=	bin/gitlab-runner

# Since v19.x the go.mod has a local path replace
# (helpers/runner_wrapper/api). The framework's go-post-fetch hook runs
# "go mod download all" from the distdir, where only the bare go.mod has
# been fetched, and resolves that local path relative to it. Extract the
# subtree from the main tarball first (this runs before go-post-fetch).
post-fetch:
	@${MKDIR} ${DISTDIR}/${DIST_SUBDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && \
		${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}.tar.bz2 \
		--strip-components 1 --no-same-owner --no-same-permissions \
		${DISTNAME}/helpers/runner_wrapper/api

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
