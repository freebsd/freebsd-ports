# New ports collection makefile for:	p5-Class-Roles
# Date Created:				17 Feb, 2004
# Whom:					Alex Kapranoff <kappa@freebsd.org.ua>
#
# $FreeBSD$
#

PORTNAME=	Class-Roles
PORTVERSION=	0.30
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@freebsd.org
COMMENT=	Provides a role-based system of OOP (emulates Perl6)

BUILD_DEPENDS=	${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Class::Roles.3

.include <bsd.port.mk>
