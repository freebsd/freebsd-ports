# New ports collection makefile for:	Business::OnlinePayment::TCLink
# Date created:				24 October 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Business-OnlinePayment-TCLink
PORTVERSION=	1.01
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Business
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A Business::OnlinePayment backend module for TrustCommerce

BUILD_DEPENDS=	${SITE_PERL}/Business/CreditCard.pm:${PORTSDIR}/misc/p5-Business-CreditCard \
		${SITE_PERL}/Business/OnlinePayment.pm:${PORTSDIR}/misc/p5-Business-OnlinePayment \
		${SITE_PERL}/${PERL_ARCH}/Net/TCLink.pm:${PORTSDIR}/net/p5-Net-TCLink
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

MAN3=		Business::OnlinePayment::TCLink.3

.include <bsd.port.mk>
