PORTNAME=	simplecov
PORTVERSION=	0.21.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Powerful configuration library and automatic merging of coverage across test suites
WWW=		https://github.com/simplecov-ruby/simplecov

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-docile>=1.1<2:devel/rubygem-docile \
		rubygem-simplecov-html>=0.11<1:textproc/rubygem-simplecov-html \
		rubygem-simplecov_json_formatter>=0.1<1:devel/rubygem-simplecov_json_formatter

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
