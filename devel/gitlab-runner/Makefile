# $FreeBSD$

PORTNAME=	gitlab-runner
PORTVERSION=	9.5.0
CATEGORIES=	devel
MASTER_SITES=	\
		https://gitlab.com/gitlab-org/gitlab-ci-multi-runner/repository/archive.tar.bz2?ref=v${PORTVERSION}&dummy=/ \
		https://gitlab-ci-multi-runner-downloads.s3.amazonaws.com/master/docker/:dockerx64 \
		https://gitlab-ci-multi-runner-downloads.s3.amazonaws.com/master/docker/:dockerarm
DISTFILES=	\
		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		prebuilt-x86_64.tar.xz:dockerx64 \
		prebuilt-arm.tar.xz:dockerarm
DIST_SUBDIR=	gitlab-runner
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Official GitLab Runner written in Go

BUILD_DEPENDS=	go:lang/go \
		go-bindata:devel/go-bindata
RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		bash:shells/bash \
		git:devel/git

USES=		tar:bz2
GITHASH=	413da38a72634601bf435f6215d6669cd5a4e40e
GITREV=		413da38
GITBRANCH=	9-5-stable
WRKSRC=		${WRKDIR}/gitlab-ci-multi-runner-v${PORTVERSION}-${GITHASH}

PLIST_FILES=	bin/gitlab-runner

USE_RC_SUBR=	gitlab_runner

USERS=		gitlab-runner
GROUPS=		gitlab-runner

post-extract:
	@${MKDIR} ${WRKSRC}/out/docker/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/prebuilt-x86_64.tar.xz ${WRKSRC}/out/docker/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/prebuilt-arm.tar.xz ${WRKSRC}/out/docker/

post-patch:
	@${REINPLACE_CMD} \
		-e "s!%%VERSION%%!${PORTVERSION}!g" \
		-e "s!%%REVISION%%!${GITREV}!g" \
		-e "s!%%BRANCH%%!${GITBRANCH}!g" \
		${WRKSRC}/common/version.go

do-build:
	@cd ${WRKSRC} && go-bindata \
		-pkg docker \
		-nocompress \
		-nomemcopy \
		-nometadata \
		-prefix out/docker/ \
		-o executors/docker/bindata.go \
		out/docker/prebuilt-x86_64.tar.xz \
		out/docker/prebuilt-arm.tar.xz
	@cd ${WRKSRC} && go fmt executors/docker/bindata.go
	@${MV} ${WRKSRC}/vendor ${WRKSRC}/src
	@${MKDIR} ${WRKSRC}/src/gitlab.com/gitlab-org
	@${LN} -s ${WRKSRC} ${WRKSRC}/src/gitlab.com/gitlab-org/gitlab-ci-multi-runner
	@cd ${WRKSRC} && ${SETENV} CGO_ENABLED=0 GOPATH=${WRKSRC} go build -o gitlab-ci-multi-runner

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gitlab-ci-multi-runner ${STAGEDIR}${PREFIX}/bin/gitlab-runner

.include <bsd.port.mk>
