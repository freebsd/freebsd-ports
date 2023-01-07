PORTNAME=	dify
DISTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	CRATESIO
# XXX Teach USES=cargo to have proper default
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Fast pixel-by-pixel image comparison tool in Rust
WWW=		https://github.com/jihchi/dify

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
