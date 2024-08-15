PORTNAME=	etcd
PORTVERSION=	3.4.18
DISTVERSIONPREFIX=	v
PORTREVISION=	25
CATEGORIES=	devel
PKGNAMEPREFIX=	coreos-
PKGNAMESUFFIX=	34

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Highly-available key value store and service discovery
WWW=		https://github.com/coreos/etcd

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	coreos
GH_TUPLE=	golang:sys:v0.5.0:golang_sys

GO_PKGNAME=	github.com/coreos/etcd
GO_TARGET=	. ./etcdctl

CONFLICTS_INSTALL=	coreos-etcd[0-9][0-9]

PLIST_FILES=	bin/etcd \
		bin/etcdctl
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS
DOCS_DESC=	Install etcd README file

pre-patch:
	${RM} ${WRKSRC}/vendor/modules.txt
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
