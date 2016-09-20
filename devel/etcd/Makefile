# $FreeBSD$

PORTNAME=	etcd
PORTVERSION=	2.3.7
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	coreos-

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Highly-available key value store and service discovery

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=coreos-etcdctl-0.* coreos-etcd3-*

PORTSCOUT=	limit:^2.*

USES=		go
GO_PKGNAME=	github.com/coreos/etcd
GO_TARGET=	github.com/coreos/etcd \
		github.com/coreos/etcd/etcdctl
USE_GITHUB=	yes
GH_ACCOUNT=	coreos

PLIST_FILES=	bin/etcd \
		bin/etcdctl
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS
DOCS_DESC=	Install etcd README file

do-install:
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/etcd ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/etcdctl ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
