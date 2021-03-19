# $FreeBSD$

PORTNAME=	soju
DISTVERSION=	0.0.20201214
CATEGORIES=	irc
MASTER_SITES=	https://git.sr.ht/~emersion/go-scfg/archive/:goscfg
DISTFILES=	${GO_SCFG_REV}.tar.gz:goscfg

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	IRC bouncer

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

OPTIONS_DEFAULT=	DOCS
OPTIONS_DEFINE=		DOCS

USE_GITHUB=	yes
GH_ACCOUNT=	emersion
GH_TAGNAME=	0ddc0de
GH_TUPLE=	emersion:go-sasl:7bfe0ed36a21:emersion_go_sasl/vendor/github.com/emersion/go-sasl \
		go-irc:irc:v3.1.3:go_irc_irc/vendor/gopkg.in/irc.v3 \
		golang:crypto:9e8e0b390897:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:9f70ab9862d5:golang_sys/vendor/golang.org/x/sys \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		klauspost:compress:v1.11.1:klauspost_compress/vendor/github.com/klauspost/compress \
		mattn:go-sqlite3:v1.14.4:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		pires:go-proxyproto:v0.2.0:pires_go_proxyproto/vendor/github.com/pires/go-proxyproto \
		nhooyr:websocket:v1.8.6:nhooyr_websocket/vendor/nhooyr.io/websocket
GO_SCFG_REV=	142a8aa629fc

GO_PKGNAME=	./cmd/soju ./cmd/sojuctl
PLIST_FILES=	bin/soju \
		bin/sojuctl

DOCS_BUILD_DEPENDS=	scdoc:textproc/scdoc
DOCS_PLIST_FILES=	man/man1/soju.1.gz

post-extract:
	${MKDIR} ${WRKSRC}/vendor/git.sr.ht/~emersion
	${MV} ${WRKDIR}/go-scfg-${GO_SCFG_REV} ${WRKSRC}/vendor/git.sr.ht/~emersion/go-scfg

post-build-DOCS-on:
	${LOCALBASE}/bin/scdoc <${WRKSRC}/doc/${PORTNAME}.1.scd >${WRKSRC}/doc/${PORTNAME}.1

post-install-DOCS-on:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
