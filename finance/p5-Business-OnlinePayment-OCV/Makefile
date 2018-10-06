# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Business-OnlinePayment-OCV
PORTVERSION=	0.01
PORTREVISION=	2
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Business::OnlinePayment backend module for OCV

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Business-OCV>=0:finance/p5-Business-OCV \
		p5-Business-OnlinePayment>=0:finance/p5-Business-OnlinePayment

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
