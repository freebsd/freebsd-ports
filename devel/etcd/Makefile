# $FreeBSD$

PORTNAME=	etcd
PORTVERSION=	2.3.6
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	coreos-

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Highly-available key value store and service discovery

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

CONFLICTS_INSTALL=coreos-etcdctl-0.*

USE_GITHUB=	yes
GH_ACCOUNT=	coreos

PLIST_FILES=	bin/etcd \
		bin/etcdctl
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS
DOCS_DESC=	Install etcd README file

do-build:
	cd ${WRKSRC}; ${SH} build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/etcd ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/etcdctl ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
