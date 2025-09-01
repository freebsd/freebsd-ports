PORTNAME=	oxipng
DISTVERSIONPREFIX=	v
DISTVERSION=	9.1.5 # apply ${FILESDIR}/patch-man before generating cargo-crates list for missing deps
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Multithreaded PNG optimizer written in Rust
WWW=		https://github.com/shssoichiro/oxipng

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	shssoichiro

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

post-build:
	(cd ${WRKSRC} && cargo xtask mangen)

post-install:
	${INSTALL_MAN} ${WRKSRC}/target/xtask/mangen/manpages/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
