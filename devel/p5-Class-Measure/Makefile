# New ports collection makefile for:	p5-Class-Measure
# Date created:		2006-10-23
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Class-Measure
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create, compare, and convert units of measurement

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Sub-Exporter>=0.982:${PORTSDIR}/devel/p5-Sub-Exporter

PERL_CONFIGURE=	yes

MAN3=		Class::Measure.3 Class::Measure::Length.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.82:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
