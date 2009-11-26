# New ports collection makefile for:	p5-constant-lexical
# Date created:		2008-11-16
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	constant-lexical
PORTVERSION=	1.00000
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/S/SP/SPROUT
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Perl pragma to declare lexical compile-time constants

RUN_DEPENDS=	p5-Sub-Delete>0:${PORTSDIR}/devel/p5-Sub-Delete

PERL_CONFIGURE=	yes
USE_PERL5=	5.8.0+

MAN3=		constant::lexical.3

.include <bsd.port.mk>
