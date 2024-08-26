PORTNAME=	rust-script
DISTVERSION=	0.34.0
PORTREVISION=	5
CATEGORIES=	devel

MAINTAINER=	pat@patmaddox.com
COMMENT=	Run Rust files and expressions as scripts without setup or compilation
WWW=		https://github.com/fornwall/rust-script

LICENSE=	APACHE20

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	fornwall
GH_PROJECT=	rust-script

PLIST_FILES=	bin/rust-script

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rust-script

.include <bsd.port.mk>
