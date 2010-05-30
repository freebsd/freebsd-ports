# New ports collection makefile for:	p5-Test-Module-Used
# Date created:		2010-01-14
# Whom:			Takuya Tsuchida <tsucchi@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Module-Used
PORTVERSION=	0.2.0
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tsucchi@cpan.org
COMMENT=	Test required module is really used and vice versa

RUN_DEPENDS=	p5-YAML>=0.68:${PORTSDIR}/textproc/p5-YAML \
		p5-List-MoreUtils>=0.24:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Module-CoreList>=2.18:${PORTSDIR}/devel/p5-Module-CoreList \
		p5-PPI>=1.205:${PORTSDIR}/textproc/p5-PPI \
		p5-version>=0.77:${PORTSDIR}/devel/p5-version \
		p5-Module-Used>=v1.2.0:${PORTSDIR}/devel/p5-Module-Used
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes
MAN3=		Test::Module::Used.3

.include <bsd.port.mk>
