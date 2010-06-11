# New ports collection makefile for:	Data-Section
# Date created:		27 December 2009
# Whom:		Andrey Kostenko <andrey@kostenko.name>
#
# $FreeBSD$
#

PORTNAME=	Data-Section
PORTVERSION=	0.101620
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read multiple hunks of data out of your DATA section

BUILD_DEPENDS=	p5-Sub-Exporter>=0.979:${PORTSDIR}/devel/p5-Sub-Exporter
RUN_DEPENDS=	p5-Sub-Exporter>=0.979:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat
TEST_DEPENDS=	p5-Test-Simple>=0.90:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	YES

MAN3=	Data::Section.3

.include <bsd.port.mk>
