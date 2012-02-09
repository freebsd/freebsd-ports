# New ports collection makefile for:	Params::Validate
# Date created:				10 April 2001
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	Params-Validate
PORTVERSION=	1.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Validate method/function parameters

LICENSE=	ART20

BUILD_DEPENDS=	p5-Module-Implementation>=0.04:${PORTSDIR}/devel/p5-Module-Implementation
RUN_DEPENDS=	p5-Module-Implementation>=0.04:${PORTSDIR}/devel/p5-Module-Implementation

TEST_DEPENDS=	p5-Readonly>=0:${PORTSDIR}/devel/p5-Readonly \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Taint>=0.02:${PORTSDIR}/devel/p5-Test-Taint

PERL_MODBUILD=	yes

MAN3=		Attribute::Params::Validate.3 \
		Params::Validate.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-Attribute-Handlers>=0.79:${PORTSDIR}/devel/p5-Attribute-Handlers
RUN_DEPENDS+=	p5-Attribute-Handlers>=0.79:${PORTSDIR}/devel/p5-Attribute-Handlers
.endif

.if ${PERL_LEVEL} < 501000
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
