# $FreeBSD$

PORTNAME=	etcd
PORTVERSION=	3.0.16
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	coreos-
PKGNAMESUFFIX=	3

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Highly-available key value store and service discovery

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=coreos-etcdctl-0.* coreos-etcd-*

USES=		go
GO_PKGNAME=	github.com/coreos/etcd
GO_TARGET=	github.com/coreos/etcd \
		github.com/coreos/etcdctl
USE_GITHUB=	yes
GH_ACCOUNT=	coreos

PLIST_FILES=	bin/etcd \
		bin/etcdctl
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS
DOCS_DESC=	Install etcd README file

post-extract:
	@${MV} ${WRKSRC}/cmd/vendor ${WRKDIR}/src
	@${RM} ${GO_WRKDIR_SRC}/github.com/${GH_ACCOUNT}/${PORTNAME}
	@${LN} -s ${WRKSRC} ${GO_WRKDIR_SRC}/github.com/${GH_ACCOUNT}/etcd
	@${LN} -s ${WRKSRC}/etcdctl ${GO_WRKDIR_SRC}/github.com/${GH_ACCOUNT}/etcdctl

do-install:
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/etcd ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/etcdctl ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
