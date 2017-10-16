# $FreeBSD$

PORTNAME=	gitlab-runner
PORTVERSION=	10.0.2
CATEGORIES=	devel
MASTER_SITES=	\
		https://gitlab.com/gitlab-org/gitlab-runner/repository/archive.tar.bz2?ref=v${PORTVERSION}&dummy=/ \
		https://gitlab-runner-downloads.s3.amazonaws.com/master/docker/:dockerx64 \
		https://gitlab-runner-downloads.s3.amazonaws.com/master/docker/:dockerarm
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
GITHASH=	a9a76a502bf69371d9c610d0b2814b4e0f3ae762
GITREV=		a9a76a50
GITBRANCH=	10-0-stable
BUILT=		2017-10-04T12:39:04-00:00
WRKSRC=		${WRKDIR}/gitlab-runner-v${PORTVERSION}-${GITHASH}
GO_LDFLAGS=	-X gitlab.com/gitlab-org/gitlab-runner/common.VERSION=${PORTVERSION} \
		-X gitlab.com/gitlab-org/gitlab-runner/common.REVISION=${GITREV} \
		-X gitlab.com/gitlab-org/gitlab-runner/common.BUILT=${BUILT} \
		-X gitlab.com/gitlab-org/gitlab-runner/common.BRANCH=${GITBRANCH} \
		-s -w                                           

PLIST_FILES=	bin/gitlab-runner

USE_RC_SUBR=	gitlab_runner

USERS=		gitlab-runner
GROUPS=		gitlab-runner

post-extract:
	@${MKDIR} ${WRKSRC}/out/docker/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/prebuilt-x86_64.tar.xz ${WRKSRC}/out/docker/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/prebuilt-arm.tar.xz ${WRKSRC}/out/docker/

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
	@${LN} -s ${WRKSRC} ${WRKSRC}/src/gitlab.com/gitlab-org/gitlab-runner
	@cd ${WRKSRC} && \
		${SETENV} CGO_ENABLED=0 GOPATH=${WRKSRC} go build \
			-ldflags="${GO_LDFLAGS}" \
			-o gitlab-runner

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gitlab-runner ${STAGEDIR}${PREFIX}/bin/gitlab-runner

.include <bsd.port.mk>
