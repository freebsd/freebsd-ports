# New ports collection makefile for:	p5-WWW-Mechanize
# Date created:				2005-02-13
# Whom:	      				aturetta@commit.it
#
# $FreeBSD$
#

PORTNAME=	Test-WWW-Mechanize
PORTVERSION=	1.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	fbsdports@commit.it
COMMENT=	Testing-specific WWW::Mechanize subclass

BUILD_DEPENDS=	${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize \
		${SITE_PERL}/Test/LongString.pm:${PORTSDIR}/devel/p5-Test-LongString
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::WWW::Mechanize.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/Test/Builder.pm:${PORTSDIR}/devel/p5-Test-Simple
.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.x or later. Install lang/perl5.8 then try again
.endif
.endif

.include <bsd.port.post.mk>
