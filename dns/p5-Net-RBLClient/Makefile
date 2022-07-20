PORTNAME=	Net-RBLClient
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Queries multiple Realtime Blackhole Lists in parallel

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Net-DNS>=0:dns/p5-Net-DNS

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes
WRKSRC=		${WRKDIR}/RBLCLient-${PORTVERSION}

.include <bsd.port.mk>
