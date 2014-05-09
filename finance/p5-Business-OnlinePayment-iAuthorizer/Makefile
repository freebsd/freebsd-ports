# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Business-OnlinePayment-iAuthorizer
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Business::OnlinePayment backend module for iAuthorizer

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Business-OnlinePayment>=0:${PORTSDIR}/finance/p5-Business-OnlinePayment
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
