PORTNAME=	ruby_memcheck
PORTVERSION=	2.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Use Valgrind memcheck without going crazy
WWW=		https://github.com/Shopify/ruby_memcheck

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-nokogiri>=0:textproc/rubygem-nokogiri \
		valgrind>=3.20.0,1:devel/valgrind

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/ruby_memcheck

.include <bsd.port.mk>
