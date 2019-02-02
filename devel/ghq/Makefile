# $FreeBSD$

PORTNAME=	ghq
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Remote repository management made easy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go>=1.8,1:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	motemen
GH_SUBDIR=	src/github.com/motemen/ghq
GH_TUPLE=	urfave:cli:b67dcf995b6a7b7f14fad5fcb7cc5441b05e814b:cli/src/github.com/urfave/cli \
		motemen:go-colorine:45d19169413a019e4e2be69629dde5c7d92f8706:go_colorine/src/github.com/motemen/go-colorine \
		daviddengcn:go-colortext:186a3d44e9200d7eb331356ca4864f52708e1399:go_colortext/src/github.com/daviddengcn/go-colortext \
		mitchellh:go-homedir:af06845cf3004701891bf4fdb884bfe4920b3727:go_homedir/src/github.com/mitchellh/go-homedir

MAKE_ENV=	GOPATH=${WRKSRC}
PLIST_FILES=	bin/ghq \
		share/zsh/site-functions/_ghq

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
MANPAGES_PLIST_FILES=	man/man1/ghq.1.gz

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} go build -o ${WRKSRC}/ghq \
		-ldflags "-X \"main.Version=${PKGVERSION}\""

do-build-MANPAGES-on:
	cd ${WRKSRC} && asciidoctor -b manpage -d manpage ghq.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ghq ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/zsh/_ghq \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

do-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/ghq.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
