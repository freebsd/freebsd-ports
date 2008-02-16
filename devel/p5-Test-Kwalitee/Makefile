# New ports collection makefile for:	p5-Test-Kwalitee
# Date created:		2008-02-14
# Whom:			Felippe de Meirelles Motta <lippemail@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Test-Kwalitee
PORTVERSION=	0.30
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippemail@gmail.com
COMMENT=	Test the Kwalitee of a distribution before you release it

BUILD_DEPENDS+=	${SITE_PERL}/Module/CPANTS/Analyse.pm:${PORTSDIR}/devel/p5-Module-CPANTS-Analyse \
		${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Test/Pod/Coverage.pm:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod \
		${SITE_PERL}/Module/Signature.pm:${PORTSDIR}/security/p5-Module-Signature
RUN_DEPENDS+=	${SITE_PERL}/Module/CPANTS/Analyse.pm:${PORTSDIR}/devel/p5-Module-CPANTS-Analyse \
		${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Test/Pod/Coverage.pm:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod \
		${SITE_PERL}/Module/Signature.pm:${PORTSDIR}/security/p5-Module-Signature

PERL_CONFIGURE=	5.6.1+

MAN3=		Test::Kwalitee.3

.include <bsd.port.mk>
