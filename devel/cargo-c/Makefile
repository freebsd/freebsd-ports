PORTNAME=	cargo-c
DISTVERSION=	0.10.14
DISTVERSIONSUFFIX=	+cargo-0.89.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	CRATESIO
# XXX Teach USES=cargo to have proper default
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Cargo C-ABI helpers
WWW=		https://github.com/lu-zero/cargo-c

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libcurl.so:ftp/curl \
		libssh2.so:security/libssh2

USES=		cargo ssl
PLIST_FILES=	bin/cargo-capi \
		bin/cargo-cbuild \
		bin/cargo-cinstall \
		bin/cargo-ctest \
		${NULL}

.include <bsd.port.pre.mk>

# prevent address space exhaustion on armv6/armv7
.if ${ARCH:Marmv?} || ${ARCH} == powerpc
LTO_UNSAFE=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,libdir.join("pkgconfig,prefix.join("libdata/pkgconfig,' \
		${WRKSRC}/src/install.rs

.include <bsd.port.post.mk>
