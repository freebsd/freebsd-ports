PORTNAME=	soju
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
PORTREVISION=	4
CATEGORIES=	irc
MASTER_SITES=	https://git.sr.ht/~emersion/go-scfg/archive/:goscfg \
		https://git.sr.ht/~sircmpwn/go-bare/archive/:gobare
DISTFILES=	${GO_SCFG_REV}.tar.gz:goscfg \
		${GO_BARE_REV}.tar.gz:gobare

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	IRC bouncer

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules sqlite:3

OPTIONS_DEFAULT=	DOCS
OPTIONS_DEFINE=		DOCS

USE_GITHUB=	yes
GH_ACCOUNT=	emersion
GH_TUPLE=	beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.2:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		emersion:go-sasl:0b9dcfb154ac:emersion_go_sasl/vendor/github.com/emersion/go-sasl \
		go-irc:irc:v3.1.4:go_irc_irc/vendor/gopkg.in/irc.v3 \
		golang:crypto:86341886e292:golang_crypto/vendor/golang.org/x/crypto \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:4e6760a101f9:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		golang:time:0e9765cccd65:golang_time/vendor/golang.org/x/time \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		klauspost:compress:v1.14.4:klauspost_compress/vendor/github.com/klauspost/compress \
		lib:pq:v1.10.4:lib_pq/vendor/github.com/lib/pq \
		mattn:go-sqlite3:v1.14.12:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		nhooyr:websocket:v1.8.7:nhooyr_websocket/vendor/nhooyr.io/websocket \
		pires:go-proxyproto:v0.6.2:pires_go_proxyproto/vendor/github.com/pires/go-proxyproto \
		prometheus:client_golang:v1.12.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.32.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.7.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf

GO_BARE_REV=	ab86bc2846d9
GO_SCFG_REV=	c2c7a15d6c99
GO_BUILDFLAGS+=	-tags=libsqlite3
CGO_LDFLAGS+=	-lsqlite3
GO_PKGNAME=	./cmd/soju ./cmd/sojuctl ./contrib/znc-import.go
PLIST_FILES=	bin/soju \
		bin/sojuctl \
		bin/soju-znc-import \
		${DOCSDIR_REL}/getting-started.md

DOCS_BUILD_DEPENDS=	scdoc:textproc/scdoc
DOCS_PLIST_FILES=	man/man1/soju.1.gz \

post-extract:
	${MKDIR} ${WRKSRC}/vendor/git.sr.ht/~emersion ${WRKSRC}/vendor/git.sr.ht/~sircmpwn
	${MV} ${WRKDIR}/go-scfg-${GO_SCFG_REV} ${WRKSRC}/vendor/git.sr.ht/~emersion/go-scfg
	${MV} ${WRKDIR}/go-bare-${GO_BARE_REV} ${WRKSRC}/vendor/git.sr.ht/~sircmpwn/go-bare

post-build-DOCS-on:
	${LOCALBASE}/bin/scdoc <${WRKSRC}/doc/${PORTNAME}.1.scd >${WRKSRC}/doc/${PORTNAME}.1

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}${PREFIX}/bin/znc-import.go ${STAGEDIR}${PREFIX}/bin/soju-znc-import
	${INSTALL_MAN} ${WRKSRC}/doc/getting-started.md ${STAGEDIR}${DOCSDIR}

post-install-DOCS-on:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
