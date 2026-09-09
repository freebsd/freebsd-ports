PORTNAME=	amp
DISTVERSION=	0.7.1-69
DISTVERSIONSUFFIX=	-gdf97a3c
CATEGORIES=	editors

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Complete text editor for your terminal
WWW=		https://amp.rs/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	jmacdonald

_GIT_HEAD=	df97a3c
CARGO_ENV=	BUILD_REVISION=${_GIT_HEAD}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
