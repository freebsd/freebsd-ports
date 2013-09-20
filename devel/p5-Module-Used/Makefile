# Created by: Takuya Tsuchida <tsucchi@cpan.org>
# $FreeBSD$

PORTNAME=	Module-Used
PORTVERSION=	v1.2.0
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tsucchi@cpan.org
COMMENT=	Find modules loaded by Perl code without running it

RUN_DEPENDS=	p5-File-Next>=1.02:${PORTSDIR}/sysutils/p5-File-Next \
		p5-PPI>=1.203:${PORTSDIR}/textproc/p5-PPI \
		p5-version>=0.74:${PORTSDIR}/devel/p5-version \
		p5-Test-Deep>=0.098:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Readonly>=1.03:${PORTSDIR}/devel/p5-Readonly
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=	Module::Used.3
MAN1=	modules-used.1

NO_STAGE=	yes
.include <bsd.port.mk>
