# New ports collection makefile for:	Business::OnlinePayment::Cardstream
# Date created:				24 October 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Business-OnlinePayment-Cardstream
PORTVERSION=	1.0
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Business
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A Business::OnlinePayment backend module for Cardstream

BUILD_DEPENDS=	${SITE_PERL}/Business/CreditCard.pm:${PORTSDIR}/misc/p5-Business-CreditCard \
		${SITE_PERL}/Business/OnlinePayment.pm:${PORTSDIR}/misc/p5-Business-OnlinePayment
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

MAN3=		Business::OnlinePayment::Cardstream.3

.include <bsd.port.mk>
