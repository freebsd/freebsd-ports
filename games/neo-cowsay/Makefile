# $FreeBSD$

PORTNAME=	neo-cowsay
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
CATEGORIES=	games

MAINTAINER=	ed.arrakis@gmail.com
COMMENT=	Neo Cowsay written in Go

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	Code-Hex
GH_PROJECT=	Neo-cowsay
GH_TUPLE=	\
		Code-Hex:go-wordwrap:v1.0.0:code_hex_go_wordwrap/vendor/github.com/Code-Hex/go-wordwrap \
		golang:crypto:74369b46fc67:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:a9d3bda3a223:golang_sys/vendor/golang.org/x/sys \
		jessevdk:go-flags:v1.4.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		mattn:go-colorable:v0.1.1:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.5:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.7:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors
GO_TARGET=	./cmd/cowsay:neo-cowsay ./cmd/cowthink:neo-cowthink

PLIST_FILES=	bin/neo-cowsay bin/neo-cowthink

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
.for l in neo-cowsay neo-cowthink
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${l}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
