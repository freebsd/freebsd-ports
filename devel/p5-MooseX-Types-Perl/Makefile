PORTNAME=	MooseX-Types-Perl
PORTVERSION=	0.101343
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Moose types that check against Perl syntax

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-MooseX-Types>=0:devel/p5-MooseX-Types \
		p5-Params-Util>=0:devel/p5-Params-Util

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
