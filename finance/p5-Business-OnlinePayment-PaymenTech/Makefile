# New ports collection makefile for:	p5-Business-OnlinePayment-PaymenTech
# Date created:				2008/08/31
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Business-OnlinePayment-PaymenTech
PORTVERSION=	1.5
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	PaymenTech backend for Business::OnlinePayment

BUILD_DEPENDS=	${SITE_PERL}/Business/OnlinePayment.pm:${PORTSDIR}/finance/p5-Business-OnlinePayment \
		p5-Module-Install>=0:${PORTSDIR}/devel/p5-Module-Install
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Business::OnlinePayment::PaymenTech.3

post-extract:
	@${PERL} -i.bak -ne 'print unless /^(test_requires|auto_install|recommends|configure_requires)/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
