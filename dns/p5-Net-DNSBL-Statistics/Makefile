PORTNAME=	Net-DNSBL-Statistics
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	dns mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Gather DNSBL Statistics

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Net-DNS-Codes>=0.09:dns/p5-Net-DNS-Codes \
		p5-Net-DNS-ToolKit>=0.41:dns/p5-Net-DNS-ToolKit \
		p5-Net-DNSBL-MultiDaemon>=0.26:dns/p5-Net-DNSBL-MultiDaemon

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
