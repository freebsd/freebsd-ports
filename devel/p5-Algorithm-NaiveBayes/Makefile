# New ports collection makefile for:	Algorithm::NaiveBayes
# Date created:				Oct 25 2003
# Whom:					clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Algorithm-NaiveBayes
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Algorithm
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl class performing Bayesian prediction of categories

PERL_MODBUILD=	yes

MAN3=		Algorithm::NaiveBayes.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/List/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/List/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
