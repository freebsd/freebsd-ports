# New ports collection makefile for:	devel/p5-Data-GUID
# Date created:				05 April 2007
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-GUID
PORTVERSION=	0.046
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/../../authors/id/R/RJ/RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Generate globally unique identifiers

BUILD_DEPENDS=	p5-Sub-Install>=0.03:${PORTSDIR}/devel/p5-Sub-Install \
		p5-Sub-Exporter>=0.90:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-Data-UUID>=1.148:${PORTSDIR}/devel/p5-Data-UUID
RUN_DEPENDS=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=	Data::GUID.3

.include <bsd.port.mk>
