PORTNAME=	uv
DISTVERSION=	0.8.3
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extremely fast Python package installer and resolver, written in Rust
WWW=		https://astral.sh/ \
		https://docs.astral.sh/uv/ \
		https://github.com/astral-sh/uv

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BROKEN_armv7=	compilation fails: rustc-LLVM ERROR: out of memory
BROKEN_i386=	compilation of the libopenssl_sys-abc7d27a34743709 crate fails: ld: error: undefined symbol: __atomic_is_lock_free, etc

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2 \
		libzstd.so:archivers/zstd

USES=		cargo gmake localbase perl5 pkgconfig
USE_PERL5=	build

USE_GITHUB=	yes
GH_ACCOUNT=	astral-sh

OPENSSLINC=	/usr/include
OPENSSLLIB=	/usr/lib

PROGS=		uv uvx

PLIST_FILES=	${PROGS:S/^/bin\//}

PORTSCOUT=	limit:.*\..*$$ # prevent tags like perma-39

do-install:
# workaround for error: found a virtual manifest at `xx` instead of a package manifest
.for p in ${PROGS}
	${INSTALL_PROGRAM} \
		${WRKDIR}/target/release/${p} \
		${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
