# Created by: chinsan
# $FreeBSD$

PORTNAME=	Business-OnlinePayment-PaymenTech
PORTVERSION=	2.07
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	PaymenTech backend for Business::OnlinePayment

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Business-OnlinePayment>=0:finance/p5-Business-OnlinePayment \
		p5-Module-Install>=0:devel/p5-Module-Install \
		p5-Net-HTTPS-Any>=0.10:net/p5-Net-HTTPS-Any \
		p5-XML-Simple>=0:textproc/p5-XML-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
