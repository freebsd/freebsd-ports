# New ports collection makefile for:	p5-self
# Date created:		2008-02-01
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	self
PORTVERSION=	0.34
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/G/GU/GUGOD/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provides "self" and "args" keywords in your OO program

RUN_DEPENDS=	p5-B-Hooks-Parser>0:${PORTSDIR}/devel/p5-B-Hooks-Parser \
		p5-B-OPCheck>0:${PORTSDIR}/devel/p5-B-OPCheck \
		p5-Devel-Declare>0:${PORTSDIR}/devel/p5-Devel-Declare \
		p5-Sub-Exporter>0:${PORTSDIR}/devel/p5-Sub-Exporter

PERL_CONFIGURE=	yes

MAN3=		self.3 self::implicit.3

.include <bsd.port.mk>
