# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CPAN-Mini
PORTVERSION=	1.111013
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	CPAN::Mini - create a minimal mirror of CPAN

RUN_DEPENDS=	p5-File-HomeDir>=0.57:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-libwww>=5:${PORTSDIR}/www/p5-libwww \
		p5-URI>=1:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

MAN1=	minicpan.1
MAN3=	CPAN::Mini.3 CPAN::Mini::App.3

NO_STAGE=	yes
.include <bsd.port.mk>
