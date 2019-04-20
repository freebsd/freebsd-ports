# $FreeBSD$

PORTNAME=	ghq
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Remote repository management made easy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
GO_PKGNAME=	github.com/motemen/ghq
USE_GITHUB=	yes
GH_ACCOUNT=	motemen
GH_TUPLE=	urfave:cli:b67dcf995b6a7b7f14fad5fcb7cc5441b05e814b:cli/vendor/github.com/urfave/cli \
		motemen:go-colorine:45d19169413a019e4e2be69629dde5c7d92f8706:go_colorine/vendor/github.com/motemen/go-colorine \
		daviddengcn:go-colortext:186a3d44e9200d7eb331356ca4864f52708e1399:go_colortext/vendor/github.com/daviddengcn/go-colortext \
		mitchellh:go-homedir:af06845cf3004701891bf4fdb884bfe4920b3727:go_homedir/vendor/github.com/mitchellh/go-homedir

PLIST_FILES=	bin/ghq \
		share/zsh/site-functions/_ghq

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
MANPAGES_PLIST_FILES=	man/man1/ghq.1.gz

post-build-MANPAGES-on:
	cd ${WRKSRC} && asciidoctor -b manpage -d manpage ghq.txt

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/zsh/_ghq \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/ghq.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
