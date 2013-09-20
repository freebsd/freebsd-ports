# Created by: Frederic Culot <frederic@culot.org>
# $FreeBSD$

PORTNAME=	ParseTemplate
PORTVERSION=	3.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/Parse
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Processor for templates containing Perl expressions

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

MAN3=		Parse::Template.3

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
