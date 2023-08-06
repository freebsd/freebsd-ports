PORTNAME=	bzip3
PORTVERSION=	1.3.2
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/kspalaiologos/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Better and stronger spiritual successor to BZip2
WWW=		https://github.com/kspalaiologos/bzip3

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
