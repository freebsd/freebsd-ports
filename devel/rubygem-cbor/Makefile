PORTNAME=	cbor
PORTVERSION=	0.5.9.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Library for CBOR binary object representation
WWW=		https://cbor.io/

LICENSE=	APACHE20

USES=		gem

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CONFIGURE_ARGS+=	--with-cflags="-Wno-error=incompatible-function-pointer-types"
.endif

.include <bsd.port.mk>
