# New ports collection makefile for:	Business::OnlinePayment::VirtualNet
# Date created:				24 October 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Business-OnlinePayment-VirtualNet
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Business
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	A Business::OnlinePayment backend module for Vital VirtualNet

BUILD_DEPENDS=	${SITE_PERL}/Business/CreditCard.pm:${PORTSDIR}/finance/p5-Business-CreditCard \
		${SITE_PERL}/Business/OnlinePayment.pm:${PORTSDIR}/finance/p5-Business-OnlinePayment \
		${SITE_PERL}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/File/CounterFile.pm:${PORTSDIR}/misc/p5-File-CounterFile \
		${SITE_PERL}/String/Parity.pm:${PORTSDIR}/devel/p5-String-Parity \
		${SITE_PERL}/${PERL_ARCH}/String/LRC.pm:${PORTSDIR}/devel/p5-String-LRC
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Business::OnlinePayment::VirtualNet.3

.include <bsd.port.mk>
