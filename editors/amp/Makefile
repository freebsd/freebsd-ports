PORTNAME=	amp
DISTVERSION=	0.7.0
PORTREVISION=	5
CATEGORIES=	editors

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Complete text editor for your terminal
WWW=		https://amp.rs/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libonig.so:devel/oniguruma

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	jmacdonald

PLIST_FILES=	bin/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
