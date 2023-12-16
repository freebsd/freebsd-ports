PORTNAME=	amp
DISTVERSION=	0.6.2-32
DISTVERSIONSUFFIX=	-gd9a913c
CATEGORIES=	editors

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Complete text editor for your terminal
WWW=		https://amp.rs/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libonig.so:devel/oniguruma

USES=		cargo localbase:ldflags python:build xorg
USE_GITHUB=	yes
GH_ACCOUNT=	jmacdonald
USE_XORG=	xcb

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} 's|python3|python${PYTHON_VER}|' ${WRKSRC}/cargo-crates/xcb-0.8.2/build.rs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
