# New ports collection makefile for:	devel/p5-Algorithm-Annotate
# Date created:				Mar  2004
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	Algorithm-Annotate
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/C/CL/CLKAO
PKGNAMEPREFIX=	p5-

MAINTAINER=	autrijus@autrijus.org
COMMENT=	Represent a series of changes in annotate form

BUILD_DEPENDS=	${SITE_PERL}/Algorithm/Diff.pm:${PORTSDIR}/devel/p5-Algorithm-Diff
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Algorithm::Annotate.3

.include <bsd.port.mk>
