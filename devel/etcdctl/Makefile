# $FreeBSD$

PORTNAME=	etcdctl
PORTVERSION=	0.4.6
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	coreos-

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Simple commandline client for etcd

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

DEPRECATED=	etcdctl is now part of etcd, following the change from the upstream
EXPIRATION_DATE=2016-02-04
CONFLICTS=	coreos-etcd-2.*

USE_GITHUB=	yes
GH_ACCOUNT=	coreos

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS
DOCS_DESC=	Install etcdctl README file

post-patch:
	@${REINPLACE_CMD} -e 's|$$VER|${DISTVERSION}|' ${WRKSRC}/scripts/release-version
	@${REINPLACE_CMD} -e '/VER=/d' ${WRKSRC}/scripts/release-version

do-build:
	(cd ${WRKSRC}; ${SH} build)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
