PORTNAME=	etcd
PORTVERSION=	2.3.8
DISTVERSIONPREFIX=	v
PORTREVISION=	35
CATEGORIES=	devel
PKGNAMEPREFIX=	coreos-

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Highly-available key value store and service discovery
WWW=		https://github.com/etcd-io/etcd

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go
USE_GITHUB=	yes
GH_ACCOUNT=	coreos

GO_PKGNAME=	github.com/coreos/etcd
GO_TARGET=	github.com/coreos/etcd github.com/coreos/etcd/etcdctl

CONFLICTS_INSTALL=	coreos-etcd[0-9][0-9]

PORTSCOUT=	limit:^2.*

PLIST_FILES=	bin/etcd \
		bin/etcdctl
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS
DOCS_DESC=	Install etcd README file

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
