# $FreeBSD$

PORTNAME=	etcd
PORTVERSION=	3.3.17
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	coreos-
PKGNAMESUFFIX=	33

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Highly-available key value store and service discovery

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

CONFLICTS_INSTALL=	coreos-etcd-* coreos-etcd31-* coreos-etcd32-* \
			coreos-etcd34-* coreos-etcdctl-0.*

GO_PKGNAME=	github.com/coreos/etcd
GO_TARGET=	. ./etcdctl
USE_GITHUB=	yes
GH_ACCOUNT=	coreos

PLIST_FILES=	bin/etcd \
		bin/etcdctl
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS
DOCS_DESC=	Install etcd README file

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
