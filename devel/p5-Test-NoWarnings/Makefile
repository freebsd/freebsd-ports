# New ports collection makefile for:    p5-Test-NoWarnings
# Date created:				May 12th 2004
# Whom:	      				Alex Kapranoff <alex@kapranoff.ru>
#
# $FreeBSD$
#

PORTNAME=	Test-NoWarnings
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	alex@kapranoff.ru
COMMENT=	Hide and store warnings while running test scripts

BUILD_DEPENDS=	${SITE_PERL}/Test/Tester.pm:${PORTSDIR}/devel/p5-Test-Tester
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
INSTALL_TARGET=	pure_install

MAN3=		Test::NoWarnings.3

post-patch:
	@${PERL} -i -pe 'm/INSTALLDIRS\s+=>/ and $$_ = ""' \
			${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
