# New ports collection makefile for:   p5-SSN-Validate
# Date created:        17 Jan 2006
# Whom:                tiger <tiger@whitetigersd.com>
#
# $FreeBSD$
#

PORTNAME=	SSN-Validate
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/../../authors/id/K/KM/KMELTZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl extension to do SSN Validation

BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Module/Signature.pm:${PORTSDIR}/security/p5-Module-Signature
RUN_DEPENDS+=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		SSN::Validate.3

test: all
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
