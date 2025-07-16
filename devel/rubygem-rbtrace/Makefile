PORTNAME=	rbtrace
PORTVERSION=	0.5.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Shows method calls inside another ruby process in real time
WWW=		https://github.com/tmm1/rbtrace

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-ffi>=1.0.6:devel/rubygem-ffi \
		rubygem-msgpack>=0.4.3:devel/rubygem-msgpack \
		rubygem-optimist>=3.0.0:devel/rubygem-optimist

USES=		gem

CONFIGURE_ARGS=	--with-cflags=-Wno-incompatible-function-pointer-types

PIE_UNSAFE=	yes


PLIST_FILES=	bin/rbtrace

.include <bsd.port.mk>
