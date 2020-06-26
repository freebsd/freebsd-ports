# $FreeBSD$

PORTNAME=	Log-Dispatch-Colorful
PORTVERSION=	0.03
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for logging to screen

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Filter>0:devel/p5-Filter \
		p5-IO-Stringy>=0:devel/p5-IO-Stringy \
		p5-Log-Dispatch>0:devel/p5-Log-Dispatch \
		p5-Params-Validate>0:devel/p5-Params-Validate

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
