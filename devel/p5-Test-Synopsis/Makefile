# New ports collection makefile for:	p5-Test-Synopsis
# Date created:		2010-01-17
# Whom:			Takuya Tsuchida <tsucchi@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Synopsis
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tsucchi@cpan.org
COMMENT=	Test your SYNOPSIS code in CPAN module

BUILD_DEPENDS=	p5-Filter>=1.35:${PORTSDIR}/devel/p5-Filter \
		p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	p5-Filter>=1.35:${PORTSDIR}/devel/p5-Filter \
		p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	YES
MAN3=		Test::Synopsis.3

.include <bsd.port.mk>
