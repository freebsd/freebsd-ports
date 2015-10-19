# Created by: Felippe de Meirelles Motta <lippemail@gmail.com>
# $FreeBSD$

PORTNAME=	Test-Kwalitee
PORTVERSION=	1.01
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Test the Kwalitee of a distribution before you release it

BUILD_DEPENDS=	p5-Module-CPANTS-Analyse>=0:${PORTSDIR}/devel/p5-Module-CPANTS-Analyse \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Module-Signature>=0:${PORTSDIR}/security/p5-Module-Signature
RUN_DEPENDS=	p5-Module-CPANTS-Analyse>=0:${PORTSDIR}/devel/p5-Module-CPANTS-Analyse \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Module-Signature>=0:${PORTSDIR}/security/p5-Module-Signature

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
