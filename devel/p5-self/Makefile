# New ports collection makefile for:	p5-self
# Date created:		2008-02-01
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	self
PORTVERSION=	0.15
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/G/GU/GUGOD/
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Provides "self" and "args" keywords in your OO program

RUN_DEPENDS=	${SITE_PERL}/Sub/Exporter.pm:${PORTSDIR}/devel/p5-Sub-Exporter

PERL_CONFIGURE=	yes

MAN3=		self.3

.include <bsd.port.mk>
