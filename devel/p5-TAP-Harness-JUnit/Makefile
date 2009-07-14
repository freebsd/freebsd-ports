# New ports collection makefile for:	TAP::Harness::JUnit
# Date created:		10 Apr 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	TAP-Harness-JUnit
PORTVERSION=	0.32
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to generate JUnit compatible output from TAP

RUN_DEPENDS=	\
	p5-Test-Harness>=3.05:${PORTSDIR}/devel/p5-Test-Harness \
	p5-XML-Simple>0:${PORTSDIR}/textproc/p5-XML-Simple \
	p5-Test-Deep>0:${PORTSDIR}/devel/p5-Test-Deep
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	TAP::Harness::JUnit.3

.include <bsd.port.mk>
