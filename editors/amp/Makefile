PORTNAME=	amp
DISTVERSION=	0.7.1
PORTREVISION=	12
CATEGORIES=	editors

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Complete text editor for your terminal
WWW=		https://amp.rs/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libonig.so:devel/oniguruma

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	jmacdonald

_GIT_HEAD=	dae913c
CARGO_ENV=	BUILD_REVISION=${_GIT_HEAD}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
