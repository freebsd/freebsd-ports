# $FreeBSD$

PORTNAME=	ghq
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
CATEGORIES=	devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Remote repository management made easy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
GO_PKGNAME=	github.com/motemen/ghq
USE_GITHUB=	yes
GH_ACCOUNT=	motemen
GH_TUPLE=	daviddengcn:go-colortext:186a3d44e920:go_colortext/vendor/github.com/daviddengcn/go-colortext \
		golang:net:4829fb13d2c6:net/vendor/golang.org/x/net \
		motemen:go-colorine:45d19169413a:go_colorine/vendor/github.com/motemen/go-colorine \
		urfave:cli:v1.20.0:cli/vendor/github.com/urfave/cli

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
