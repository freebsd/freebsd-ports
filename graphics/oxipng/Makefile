PORTNAME=	oxipng
DISTVERSION=	9.1.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	CRATESIO
# XXX Teach USES=cargo to have proper default
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Multithreaded PNG optimizer written in Rust
WWW=		https://github.com/shssoichiro/oxipng

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

post-install:
	${INSTALL_MAN} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/assets/*.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
