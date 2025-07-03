PORTNAME=	sccache
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.2
PORTREVISION=	6
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
PORTDOCS=	README.md docs/Architecture.md docs/Azure.md docs/Caching.md \
		docs/Configuration.md docs/Distributed.md \
		docs/DistributedFreeBSD.md docs/DistributedQuickstart.md \
		docs/GHA.md docs/Gcs.md docs/Jenkins.md docs/Local.md \
		docs/Memcached.md docs/Redis.md docs/Releasing.md \
		docs/ResponseFiles.md docs/Rust.md docs/S3.md docs/Webdav.md
SUB_FILES=	pkg-message

CARGO_FEATURES=	dist-client,dist-server

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/docs
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/${f}
.endfor

.include <bsd.port.mk>
