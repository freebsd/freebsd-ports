# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Business-OnlinePayment-AuthorizeNet
PORTVERSION=	3.23
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Business::OnlinePayment backend module for Authorize.Net

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Business-OnlinePayment>=3:finance/p5-Business-OnlinePayment \
		p5-Net-SSLeay>=0:security/p5-Net-SSLeay \
		p5-Text-CSV_XS>=0:textproc/p5-Text-CSV_XS \
		p5-Tie-IxHash>=0:devel/p5-Tie-IxHash \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-XML-Writer>=0:textproc/p5-XML-Writer
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
