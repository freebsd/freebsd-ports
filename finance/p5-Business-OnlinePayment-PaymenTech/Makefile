# Created by: chinsan
# $FreeBSD$

PORTNAME=	Business-OnlinePayment-PaymenTech
PORTVERSION=	2.05
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	PaymenTech backend for Business::OnlinePayment

BUILD_DEPENDS=	p5-Business-OnlinePayment>=0:${PORTSDIR}/finance/p5-Business-OnlinePayment \
		p5-Module-Install>=0:${PORTSDIR}/devel/p5-Module-Install \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-Net-HTTPS-Any>=0.10:${PORTSDIR}/net/p5-Net-HTTPS-Any
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
