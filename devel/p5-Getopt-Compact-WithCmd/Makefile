# Created by: Kan Sasaki <sasaki@fcc.ad.jp>
# $FreeBSD$

PORTNAME=	Getopt-Compact-WithCmd
PORTVERSION=	0.21
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Sub-command friendly, like Getopt::Compact

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Text-Table>=0:${PORTSDIR}/textproc/p5-Text-Table
RUN_DEPENDS=	p5-Text-Table>=0:${PORTSDIR}/textproc/p5-Text-Table
TEST_DEPENDS=	p5-Test-Output>=0:${PORTSDIR}/devel/p5-Test-Output \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
