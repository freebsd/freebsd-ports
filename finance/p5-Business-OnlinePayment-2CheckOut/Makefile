# New ports collection makefile for:	Business::OnlinePayment::2CheckOut
# Date created:				24 October 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Business-OnlinePayment-2CheckOut
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Business::OnlinePayment backend module for 2CheckOut authorization service

BUILD_DEPENDS=	${SITE_PERL}/Business/CreditCard.pm:${PORTSDIR}/finance/p5-Business-CreditCard \
		${SITE_PERL}/Business/OnlinePayment.pm:${PORTSDIR}/finance/p5-Business-OnlinePayment \
		${SITE_PERL}/${PERL_ARCH}/Text/CSV_XS.pm:${PORTSDIR}/textproc/p5-Text-CSV_XS
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Business::OnlinePayment::2CheckOut.3

post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1);$$1/;' \
		-e '$$_="" if /use 5/;' \
		${WRKSRC}/2CheckOut.pm

.include <bsd.port.mk>
