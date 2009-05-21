# New ports collection makefile for:	Class-Mix
# Date created:				21 May 2009
# Whom:					brix@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Class-Mix
PORTVERSION=	0.003
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	brix@FreeBSD.org
COMMENT=	Perl module for dynamic class mixing

BUILD_DEPENDS=	${SITE_PERL}/parent.pm:${PORTSDIR}/devel/p5-parent
RUN_DEPENDS=	${SITE_PERL}/parent.pm:${PORTSDIR}/devel/p5-parent

PERL_MODBUILD=	yes

MAN3=	Class::Mix.3

.include <bsd.port.mk>
