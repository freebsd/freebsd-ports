# New ports collection makefile for:   p5-SSN-Validate
# Date created:        17 Jan 2006
# Whom:                tiger <tiger@whitetigersd.com>
#
# $FreeBSD$
#

PORTNAME=	SSN-Validate
PORTVERSION=	0.15
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/K/KM/KMELTZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	tiger@whitetigersd.com
COMMENT=	Perl extension to do SSN Validation

BUILD_DEPENDS=	${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes
MAN3=		SSN::Validate.3

test: all
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
