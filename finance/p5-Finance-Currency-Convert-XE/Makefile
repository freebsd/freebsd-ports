# New ports collection makefile for:	finance/p5-Finance-Currency-Convert-XE
# Date created:				10 December 2004
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Finance-Currency-Convert-XE
PORTVERSION=	0.06
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Finance
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Finance::Currency::Convert::XE - Currency conversion module

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/${PERL_ARCH}/HTML/TokeParser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Finance::Currency::Convert::XE.3

.include <bsd.port.pre.mk>

post-patch:
	${PERL} -pi \
		-e 's/5.006/5.004/;' \
		-e '$$_="" if /use warnings/;' \
		${WRKSRC}/lib/Finance/Currency/Convert/XE.pm

.include <bsd.port.post.mk>
