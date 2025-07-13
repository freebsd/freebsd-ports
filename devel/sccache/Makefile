PORTNAME=	sccache
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Like ccache with cloud storage support
WWW=		https://github.com/mozilla/sccache

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 i386
ONLY_FOR_ARCHS_REASON=	ring crate not ported to other architectures

USES=		cargo ssl

LIB_DEPENDS+=	libzstd.so:archivers/zstd

USE_GITHUB=	yes
GH_ACCOUNT=	mozilla

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS

PLIST_FILES=	bin/sccache \
		bin/sccache-dist
PORTDOCS=	*
SUB_FILES=	pkg-message

CARGO_FEATURES=	dist-client,dist-server

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
