PORTNAME=	gitea-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	devel

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Gitea's official command line tool
WWW=		https://gitea.com/gitea/cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:1.27+,modules

GO_MODULE=	gitea.dev/cli
GO_TARGET=	./cmd/gt
GO_LDFLAGS=	-X ${GO_MODULE}/internal/version.Version=${DISTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/internal/app/upgrade.go

post-build:
	(cd ${GO_WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off \
		SOURCE_DATE_EPOCH=$$(${SED} -n 's/^TIMESTAMP = //p' ${DISTINFO_FILE}) \
		${GO_CMD} run ${GO_BUILDFLAGS} ./tools/cli-docs \
		--out ${WRKDIR}/docs)

post-install:
	${INSTALL_MAN} ${WRKDIR}/docs/man/*.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKDIR}/docs/completion/gt.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/gt.bash
	${INSTALL_DATA} ${WRKDIR}/docs/completion/gt.fish \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/gt.fish
	${INSTALL_DATA} ${WRKDIR}/docs/completion/_gt \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_gt

.include <bsd.port.mk>
