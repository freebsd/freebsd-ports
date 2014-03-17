# $FreeBSD$

PORTNAME=	etcdctl
PORTVERSION=	0.3.0
CATEGORIES=	devel
PKGNAMEPREFIX=	coreos-

MAINTAINER=	ports@robakdesign.com
COMMENT=	Simple commandline client for etcd

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	coreos
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	d0fc1fc

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS
DOCS_DESC=	Install etcdctl README file

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|$$VER|${DISTVERSION}|' ${WRKSRC}/scripts/release-version
	@${REINPLACE_CMD} -e '/VER=/d' ${WRKSRC}/scripts/release-version

do-build:
	(cd ${WRKSRC}; ${SH} build)

do-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
