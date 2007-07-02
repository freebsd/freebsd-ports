# New ports collection makefile for:	p5-WWW-Mechanize
# Date created:				2005-02-13
# Whom:	      				aturetta@commit.it
#
# $FreeBSD$
#

PORTNAME=	Test-WWW-Mechanize
PORTVERSION=	1.14
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Testing-specific WWW::Mechanize subclass

BUILD_DEPENDS=	p5-WWW-Mechanize>=1.24:${PORTSDIR}/www/p5-WWW-Mechanize \
		${SITE_PERL}/URI/file.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Carp/Assert/More.pm:${PORTSDIR}/devel/p5-Carp-Assert-More \
		${SITE_PERL}/HTTP/Server/Simple.pm:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		${SITE_PERL}/Test/LongString.pm:${PORTSDIR}/devel/p5-Test-LongString
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::WWW::Mechanize.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.x or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
