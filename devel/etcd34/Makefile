PORTNAME=	etcd
PORTVERSION=	3.4.16
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMESUFFIX=	34

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Highly-available key value store and service discovery

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	coreos

GO_PKGNAME=	github.com/coreos/etcd
GO_TARGET=	. ./etcdctl

CONFLICTS_INSTALL=	etcd-* etcd31-* etcd32-* etcd33-* etcdctl-0.*

PLIST_FILES=	bin/etcd \
		bin/etcdctl
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS
DOCS_DESC=	Install etcd README file

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
