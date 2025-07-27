PORTNAME=	cargo-tarpaulin
DISTVERSION=	0.32.8
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Code coverage tool for Rust projects
WWW=		https://github.com/xd009642/tarpaulin

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BROKEN_armv7=	compilation fails, see https://github.com/xd009642/llvm-profparser/issues/25
BROKEN_i386=	compilation fails, see https://github.com/xd009642/llvm-profparser/issues/25

USES=		cargo localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	xd009642
GH_PROJECT=	tarpaulin

OPENSSLINC=	/usr/include
OPENSSLLIB=	/usr/lib

PLIST_FILES=	bin/cargo-tarpaulin

.include <bsd.port.mk>
