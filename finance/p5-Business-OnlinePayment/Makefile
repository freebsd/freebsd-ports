# New ports collection makefile for:	Business::OnlinePayment
# Date created:				24 October 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Business-OnlinePayment
PORTVERSION=	3.00
PORTREVISION=	1
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:IVAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}_08

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A generic interface for processing online credit card payments

BUILD_DEPENDS=	p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash \
		p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Business::OnlinePayment.3 \
		Business::FraudDetect.3 \
		Business::FraudDetect::preCharge.3 \
		Business::OnlinePayment::HTTPS.3

.include <bsd.port.mk>
