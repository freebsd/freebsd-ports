# $FreeBSD$

PORTNAME=	etcd
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	coreos-

MAINTAINER=	ports@robakdesign.com
COMMENT=	Highly-available key value store and service discovery

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	coreos
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	5589b6f

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS ETCDCTL
DOCS_DESC=	Install etcd README file

ETCDCTL_DESC=	Install etcdctl commandline tool
ETCDCTL_RUN_DEPENDS=	etcdctl:${PORTSDIR}/devel/etcdctl

post-patch:
	@${REINPLACE_CMD} -e 's|$$VER|${DISTVERSION}|' ${WRKSRC}/scripts/release-version
	@${REINPLACE_CMD} -e '/VER=/d' ${WRKSRC}/scripts/release-version

do-build:
	cd ${WRKSRC}; ${SH} build

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
