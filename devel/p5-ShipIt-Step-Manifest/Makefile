# New ports collection makefile for:	p5-ShipIt-Step-Manifest
# Date created:		2010-11-28
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	ShipIt-Step-Manifest
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MA/MARCEL
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	ShipIt step for recreating the MANIFEST

RUN_DEPENDS=	p5-Dist-Joseki>=0:${PORTSDIR}/devel/p5-Dist-Joseki \
		p5-ShipIt>=0:${PORTSDIR}/devel/p5-ShipIt

PERL_CONFIGURE=	yes
USE_PERL5_RUN=	5.8.1+

MAN3=		ShipIt::Step::Manifest.3

.include <bsd.port.mk>
