PORTNAME=	ffi-yajl
PORTVERSION=	2.3.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	renchap@cocoa-x.com
COMMENT=	Ruby FFI wrapper around YAJL 2.x

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	yajl>=2.0.0:devel/yajl \
		rubygem-libyajl2>=1.2:devel/rubygem-libyajl2

USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/ffi-yajl-bench

.include <bsd.port.mk>
