# New ports collection makefile for:	Business::OnlinePayment::VirtualNet
# Date created:				24 October 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Business-OnlinePayment-VirtualNet
PORTVERSION=	0.02
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Business
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A Business::OnlinePayment backend module for Vital VirtualNet

BUILD_DEPENDS=	${SITE_PERL}/Business/CreditCard.pm:${PORTSDIR}/misc/p5-Business-CreditCard \
		${SITE_PERL}/Business/OnlinePayment.pm:${PORTSDIR}/misc/p5-Business-OnlinePayment \
		${SITE_PERL}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/File/CounterFile.pm:${PORTSDIR}/misc/p5-File-CounterFile \
		${SITE_PERL}/String/Parity.pm:${PORTSDIR}/devel/p5-String-Parity \
		${SITE_PERL}/${PERL_ARCH}/String/LRC.pm:${PORTSDIR}/devel/p5-String-LRC
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

MAN3=		Business::OnlinePayment::VirtualNet.3

.include <bsd.port.mk>
