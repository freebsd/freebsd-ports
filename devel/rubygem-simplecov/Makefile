# $FreeBSD$

PORTNAME=	simplecov
PORTVERSION=	0.11.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Powerful configuration library and automatic merging of coverage across test suites

LICENSE=	MIT

RUN_DEPENDS=	rubygem-docile>=1.1.0:${PORTSDIR}/devel/rubygem-docile \
		rubygem-multi_json>=1.0:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-simplecov-html>=0.8.0:${PORTSDIR}/textproc/rubygem-simplecov-html

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
