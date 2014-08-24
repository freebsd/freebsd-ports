# $FreeBSD$

PORTNAME=	simplecov
PORTVERSION=	0.9.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Powerful configuration library and automatic merging of coverage across test suites

LICENSE=	MIT

RUN_DEPENDS=	rubygem-docile>=1.1.0:${PORTSDIR}/devel/rubygem-docile \
		rubygem-multi_json>=0:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-simplecov-html>=0.8.0:${PORTSDIR}/textproc/rubygem-simplecov-html

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
