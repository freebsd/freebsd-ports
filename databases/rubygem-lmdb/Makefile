PORTNAME=	lmdb
PORTVERSION=	0.8.1
CATEGORIES=	databases rubygems
PORTREVISION=	1
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby bindings for OpenLDAP's LMDB
WWW=		https://github.com/doriantaylor/rb-lmdb

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/README.md

LIB_DEPENDS=	liblmdb0.so:databases/lmdb0

USES=		gem
CONFIGURE_ARGS=	--with-lmdb-include=${LOCALBASE}/lmdb0/include --with-lmdb-lib=${LOCALBASE}/lmdb0/lib
MAKE_ENV+=	CPPFLAGS="-I${LOCALBASE}/lmdb0/include" LDFLAGS="-L${LOCALBASE}/lmdb0/lib" \
		PKG_CONFIG_PATH="${LOCALBASE}/lmdb0/libdata/pkgconfig"

.include <bsd.port.mk>
