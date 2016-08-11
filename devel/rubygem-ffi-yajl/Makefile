# $FreeBSD$

PORTNAME=	ffi-yajl
PORTVERSION=	1.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	renchap@cocoa-x.com
COMMENT=	Ruby FFI wrapper around YAJL 2.x

LICENSE=	APACHE20

RUN_DEPENDS=	yajl>=2.0.0:devel/yajl \
		rubygem-ffi>=0:devel/rubygem-ffi \
		rubygem-libyajl2>=1.0.0:devel/rubygem-libyajl2

USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/ffi-yajl-bench

.include <bsd.port.mk>
