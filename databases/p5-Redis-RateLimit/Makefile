# Created by: Davíð Steinn Geirsson <david@isnic.is>
# $FreeBSD$

PORTNAME=	Redis-RateLimit
PORTVERSION=	1.0002
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	david@isnic.is
COMMENT=	Sliding window rate limiting with Redis

LICENSE=	MIT

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Carp>=1.50:devel/p5-Carp \
		p5-Digest-SHA1>=2.13:security/p5-Digest-SHA1 \
		p5-File-Share>=0.25:devel/p5-File-Share \
		p5-File-Slurp-Tiny>=0.004:devel/p5-File-Slurp-Tiny \
		p5-JSON-MaybeXS>=1.004002:converters/p5-JSON-MaybeXS \
		p5-Scalar-List-Utils>=1.55:lang/p5-Scalar-List-Utils \
		p5-Moo>=2.004000:devel/p5-Moo \
		p5-namespace-clean>=0.27:devel/p5-namespace-clean \
		p5-Redis>=1.998:databases/p5-Redis \
		p5-Try-Tiny>=0.30:lang/p5-Try-Tiny

USES=		perl5
USE_PERL5=	modbuildtiny
NO_ARCH=	yes

.include <bsd.port.mk>
