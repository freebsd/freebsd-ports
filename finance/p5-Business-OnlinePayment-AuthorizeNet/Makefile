# New ports collection makefile for:	Business::OnlinePayment::AuthorizeNet
# Date created:				24 October 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Business-OnlinePayment-AuthorizeNet
PORTVERSION=	3.15
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Business
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	A Business::OnlinePayment backend module for Authorize.Net

BUILD_DEPENDS=	${SITE_PERL}/Business/CreditCard.pm:${PORTSDIR}/finance/p5-Business-CreditCard \
		${SITE_PERL}/Business/OnlinePayment.pm:${PORTSDIR}/finance/p5-Business-OnlinePayment \
		${SITE_PERL}/${PERL_ARCH}/Text/CSV_XS.pm:${PORTSDIR}/textproc/p5-Text-CSV_XS
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Business::OnlinePayment::AuthorizeNet.3

.include <bsd.port.mk>
