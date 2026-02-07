PORTNAME=	cbor
PORTVERSION=	0.5.9.8
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Library for CBOR binary object representation
WWW=		https://cbor.io/

LICENSE=	APACHE20

USES=		gem

PIE_UNSAFE=	yes

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CONFIGURE_ARGS+=	--with-cflags="-Wno-error=incompatible-function-pointer-types"
.endif

.include <bsd.port.mk>
