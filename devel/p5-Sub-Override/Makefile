# New ports collection makefile for:    p5-Sub-Override
# Date created:				January 4th 2005
# Whom:	      				Lars Eggert <lars.eggert@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	Sub-Override
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Sub
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	Perl extension for easily overriding subroutines

BUILD_DEPENDS=	${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Sub::Override.3

.include <bsd.port.pre.mk>

##
## this port requires PERL 5.6.x or later
##
.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
