PORTNAME=	Net-DNS-TestNS
PORTVERSION=	1.10
PORTREVISION=	2
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl extension for simulating simple Nameservers

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Net-DNS>=0.64:dns/p5-Net-DNS \
		p5-XML-LibXML>=1.53:textproc/p5-XML-LibXML

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
