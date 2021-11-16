PORTNAME=	neo-cowsay
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.1
CATEGORIES=	games

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Neo Cowsay written in Go

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	Code-Hex
GH_PROJECT=	Neo-cowsay
GH_TUPLE=	Code-Hex:go-wordwrap:v1.0.0:code_hex_go_wordwrap/vendor/github.com/Code-Hex/go-wordwrap \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v2.4.0:gdamore_tcell_v2/vendor/github.com/gdamore/tcell/v2 \
		golang:crypto:c07d793c2f9a:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:c6105e7cf70d:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.6:google_go_cmp/vendor/github.com/google/go-cmp \
		jessevdk:go-flags:v1.5.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		ktr0731:go-fuzzyfinder:v0.5.1:ktr0731_go_fuzzyfinder/vendor/github.com/ktr0731/go-fuzzyfinder \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-colorable:v0.1.11:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		nsf:termbox-go:v1.1.1:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg

GO_TARGET=	./cmd/cowsay:neo-cowsay ./cmd/cowthink:neo-cowthink

PLIST_FILES=	bin/neo-cowsay \
		bin/neo-cowthink

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install:
.for l in neo-cowsay neo-cowthink
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${l}
.endfor

.include <bsd.port.mk>
