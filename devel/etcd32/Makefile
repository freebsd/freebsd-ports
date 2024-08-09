PORTNAME=	etcd
PORTVERSION=	3.2.32
DISTVERSIONPREFIX=	v
PORTREVISION=	25
CATEGORIES=	devel
PKGNAMEPREFIX=	coreos-
PKGNAMESUFFIX=	32

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Highly-available key value store and service discovery
WWW=		https://github.com/etcd-io/etcd

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go
USE_GITHUB=	yes
GH_ACCOUNT=	coreos
GH_TUPLE=	coreos:bbolt:v1.3.7:coreos_bbolt \
		golang:sys:v0.5.0:golang_sys

GO_PKGNAME=	github.com/coreos/etcd
GO_TARGET=	./cmd/etcd ./cmd/etcdctl

CONFLICTS_INSTALL=	coreos-etcd[0-9][0-9]

PLIST_FILES=	bin/etcd \
		bin/etcdctl
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS
DOCS_DESC=	Install etcd README file

pre-patch:
	${RM} -r ${GO_WRKSRC}/cmd/vendor/github.com/coreos/bbolt
	${LN} -s ${WRKDIR}/bbolt-* ${GO_WRKSRC}/cmd/vendor/github.com/coreos/bbolt
	${RM} -r ${GO_WRKSRC}/cmd/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${GO_WRKSRC}/cmd/vendor/golang.org/x/sys

post-patch:
	${REINPLACE_CMD} -i '' "s@#cgo LDFLAGS: -ldl@@g;" ${WRKSRC}/cmd/vendor/github.com/coreos/pkg/dlopen/dlopen.go

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
