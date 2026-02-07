PORTNAME=	cargo-about
DISTVERSION=	0.8.4
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rust: Cargo plugin to generate list of all licenses for a crate
WWW=		http://embark.rs \
		https://github.com/EmbarkStudios/cargo-about

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BUILD_DEPENDS=	rust>1.85:lang/rust
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	EmbarkStudios

RUSTFLAGS=	${ARCH:S/i386/YES/:C/^[a-z].*//:S/YES/-C target-feature=+sse,+sse2/} # add sse sse2 target-features only on i386

CARGO_BUILDDEP=	no

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
LIB_DEPENDS+=	libatomic.so:lang/gcc${GCC_DEFAULT}
LDFLAGS+=	-L/usr/local/lib/gcc${GCC_DEFAULT} -latomic
.endif

.include <bsd.port.mk>
