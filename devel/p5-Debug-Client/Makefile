# Created by: ports@c0decafe.net
# $FreeBSD$

PORTNAME=	Debug-Client
PORTVERSION=	0.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	linpc@cs.nctu.edu.tw
COMMENT=	Client for the standard Perl debugger

RUN_DEPENDS=	p5-File-HomeDir>=0.98:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-PadWalker>=1.92:${PORTSDIR}/devel/p5-PadWalker \
		p5-ReadLine-Perl>=1.0303:${PORTSDIR}/devel/p5-ReadLine-Perl
TEST_DEPENDS=	p5-File-HomeDir>=0.98:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-PadWalker>=1.92:${PORTSDIR}/devel/p5-PadWalker \
		p5-ReadLine-Perl>=1.0303:${PORTSDIR}/devel/p5-ReadLine-Perl \
		p5-Test-Class>=0.36:${PORTSDIR}/devel/p5-Test-Class \
		p5-Test-Deep>=0.108:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Script>=0:${PORTSDIR}/devel/p5-Test-Script

PERL_CONFIGURE=	yes

MAN3=		Debug::Client.3

.include <bsd.port.mk>
