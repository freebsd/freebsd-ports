PORTNAME=	nickel
DISTVERSION=	1.17.0
CATEGORIES=	lang devel

MAINTAINER=	ports@nxtrn.dev
COMMENT=	Universal configuration language

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libonig.so:devel/oniguruma

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	nickel-lang

CARGO_SRC_SUBDIR=	cli
CARGO_CARGOLOCK=	${WRKSRC}/Cargo.lock
CARGO_BUILD=		yes
CARGO_INSTALL=		yes

PLIST_FILES=	bin/nickel

.include <bsd.port.mk>
