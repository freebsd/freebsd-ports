# New ports collection makefile for:	p5-Getopt-Compact-WithCmd
# Date created:				27 Feb 2012
# Whom:	      				Kan Sasaki <sasaki@fcc.ad.jp>
#
# $FreeBSD$
#

PORTNAME=	Getopt-Compact-WithCmd
PORTVERSION=	0.19
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Sub-command friendly, like Getopt::Compact

BUILD_DEPENDS=	p5-Text-Table>=0:${PORTSDIR}/textproc/p5-Text-Table
RUN_DEPENDS=	p5-Text-Table>=0:${PORTSDIR}/textproc/p5-Text-Table

TEST_DEPENDS=	p5-Test-Output>=0:${PORTSDIR}/devel/p5-Test-Output \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires

PERL_CONFIGURE=	yes

MAN3=		Getopt::Compact::WithCmd.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-Getopt-Long>=2.38:${PORTSDIR}/devel/p5-Getopt-Long
RUN_DEPENDS+=	p5-Getopt-Long>=2.38:${PORTSDIR}/devel/p5-Getopt-Long
.endif

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
