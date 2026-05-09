PORTNAME=	git-pkgs
PORTVERSION=	0.15.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Dependency tools for git
WWW=		https://git-pkgs.dev/ \
		https://github.com/git-pkgs/git-pkgs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	module modernc.org/sqlite only supported on aarch64 and amd64

USES=		go:modules

GO_BUILDFLAGS=	-ldflags="-s -w -X github.com/git-pkgs/git-pkgs/cmd.version=${PORTVERSION}"
GO_MODULE=	github.com/git-pkgs/git-pkgs

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

post-install-MANPAGES-on:
	@cd ${WRKSRC} && ${GO_CMD} run scripts/generate-man/main.go
	${INSTALL_MAN} ${WRKSRC}/man/*.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
