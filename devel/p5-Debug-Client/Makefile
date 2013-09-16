# Created by: ports@c0decafe.net
# $FreeBSD$

PORTNAME=	Debug-Client
PORTVERSION=	0.24
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pclin@FreeBSD.org
COMMENT=	Client for the standard Perl debugger

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-IO-Socket-IP>=0.18:${PORTSDIR}/net/p5-IO-Socket-IP \
		p5-PadWalker>=1.96:${PORTSDIR}/devel/p5-PadWalker \
		p5-ReadLine-Perl>=1.0303:${PORTSDIR}/devel/p5-ReadLine-Perl
TEST_DEPENDS=	p5-File-HomeDir>=1.00:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-Test-Class>=0.38:${PORTSDIR}/devel/p5-Test-Class \
		p5-Test-Deep>=0.110:${PORTSDIR}/devel/p5-Test-Deep

USES=		perl5
USE_PERL5=	configure

MAN3=		Debug::Client.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
RUN_DEPENDS+=	p5-Carp>=1.20:${PORTSDIR}/devel/p5-Carp
.endif

.if ${PERL_LEVEL} < 501600
TEST_DEPENDS+=	p5-Time-HiRes>=1.9725:${PORTSDIR}/devel/p5-Time-HiRes
.endif

.include <bsd.port.post.mk>
