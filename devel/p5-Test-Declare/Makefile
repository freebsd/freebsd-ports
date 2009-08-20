# New ports collection makefile for:	Test::Declare
# Date created:		17 Mar 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Declare
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for declarative testing

RUN_DEPENDS=	\
	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
	p5-PPI>0:${PORTSDIR}/textproc/p5-PPI \
	p5-Test-Deep>0:${PORTSDIR}/devel/p5-Test-Deep \
	p5-Test-Exception>0:${PORTSDIR}/devel/p5-Test-Exception
BUILD_DEPENDS=	\
	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
	p5-PPI>0:${PORTSDIR}/textproc/p5-PPI \
	p5-Test-Deep>0:${PORTSDIR}/devel/p5-Test-Deep \
	p5-Test-Exception>0:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	yes

MAN3=	Test::Declare.3

.include <bsd.port.mk>
