# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CPAN-Mini
PORTVERSION=	1.111013
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	CPAN::Mini - create a minimal mirror of CPAN

RUN_DEPENDS=	p5-File-HomeDir>=0.57:devel/p5-File-HomeDir \
		p5-libwww>=5:www/p5-libwww \
		p5-URI>=1:net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>=0.96:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
