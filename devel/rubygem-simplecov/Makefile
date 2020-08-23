# $FreeBSD$

PORTNAME=	simplecov
PORTVERSION=	0.19.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Powerful configuration library and automatic merging of coverage across test suites

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-docile>=1.1<2:devel/rubygem-docile \
		rubygem-simplecov-html>=0.11<1:textproc/rubygem-simplecov-html

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
