PORTNAME=	soju
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
CATEGORIES=	irc
MASTER_SITES=	https://git.sr.ht/~emersion/go-scfg/archive/:goscfg \
		https://git.sr.ht/~sircmpwn/go-bare/archive/:gobare
DISTFILES=	${GO_SCFG_REV}.tar.gz:goscfg \
		${GO_BARE_REV}.tar.gz:gobare

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	IRC bouncer

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

OPTIONS_DEFAULT=	DOCS
OPTIONS_DEFINE=		DOCS

USE_GITHUB=	yes
GH_ACCOUNT=	emersion
GH_TUPLE=	emersion:go-sasl:7bfe0ed36a21:emersion_go_sasl/vendor/github.com/emersion/go-sasl \
		go-irc:irc:v3.1.4:go_irc_irc/vendor/gopkg.in/irc.v3 \
		golang:crypto:0c34fe9e7dc2:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:4fbd30eecc44:golang_sys/vendor/golang.org/x/sys \
		golang:term:de623e64d2a6:golang_term/vendor/golang.org/x/term \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		klauspost:compress:v1.11.13:klauspost_compress/vendor/github.com/klauspost/compress \
		mattn:go-sqlite3:v1.14.6:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		nhooyr:websocket:v1.8.6:nhooyr_websocket/vendor/nhooyr.io/websocket \
		pires:go-proxyproto:v0.5.0:pires_go_proxyproto/vendor/github.com/pires/go-proxyproto

GO_BARE_REV=	46f9b5e5bcf9
GO_SCFG_REV=	142a8aa629fc
GO_PKGNAME=	./cmd/soju ./cmd/sojuctl
PLIST_FILES=	bin/soju \
		bin/sojuctl

DOCS_BUILD_DEPENDS=	scdoc:textproc/scdoc
DOCS_PLIST_FILES=	man/man1/soju.1.gz

post-extract:
	${MKDIR} ${WRKSRC}/vendor/git.sr.ht/~emersion ${WRKSRC}/vendor/git.sr.ht/~sircmpwn
	${MV} ${WRKDIR}/go-scfg-${GO_SCFG_REV} ${WRKSRC}/vendor/git.sr.ht/~emersion/go-scfg
	${MV} ${WRKDIR}/go-bare-${GO_BARE_REV} ${WRKSRC}/vendor/git.sr.ht/~sircmpwn/go-bare

post-build-DOCS-on:
	${LOCALBASE}/bin/scdoc <${WRKSRC}/doc/${PORTNAME}.1.scd >${WRKSRC}/doc/${PORTNAME}.1

post-install-DOCS-on:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
