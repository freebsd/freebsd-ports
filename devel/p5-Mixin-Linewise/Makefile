# $FreeBSD$

PORTNAME=	Mixin-Linewise
PORTVERSION=	0.004
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Write your linewise code for handles; this does the rest

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS+=	p5-Sub-Exporter>=0.900:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String
RUN_DEPENDS+=	p5-Sub-Exporter>=0.900:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
