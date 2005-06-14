# New ports collection makefile for:    p5-Test-Exception
# Date created:				January 27th 2003
# Whom:	      				Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Exception
PORTVERSION=	0.21
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Test::Exception - test functions for exception based code 

BUILD_DEPENDS=	${SITE_PERL}/Test/Builder/Tester.pm:${PORTSDIR}/devel/p5-Test-Builder-Tester \
		${SITE_PERL}/Sub/Uplevel.pm:${PORTSDIR}/devel/p5-Sub-Uplevel
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::Exception.3

.include <bsd.port.pre.mk>

##
## this port depends on devel/p5-Sub-Uplevel which
## requires PERL 5.6.x or later
##
.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
