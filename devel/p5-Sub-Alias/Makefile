# New ports collection makefile for:	devel/p5-Sub-Alias
# Date created:				2011-06-06
# Whom:					Peter Vereshagin <peter@vereshagin.org>
#
# $FreeBSD$
#

PORTNAME=	Sub-Alias
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	peter@vereshagin.org
COMMENT=	Simple subroutine alias

BUILD_DEPENDS=	p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-Devel-Declare>=0:${PORTSDIR}/devel/p5-Devel-Declare \
		p5-Devel-BeginLift>=0:${PORTSDIR}/devel/p5-Devel-BeginLift
RUN_DEPENDS=	p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-Devel-Declare>=0:${PORTSDIR}/devel/p5-Devel-Declare \
		p5-Devel-BeginLift>=0:${PORTSDIR}/devel/p5-Devel-BeginLift

PERL_CONFIGURE=	5.8.0+

LICENSE=	MIT

MAN3=		Sub::Alias.3

.include <bsd.port.mk>
