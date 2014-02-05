# $FreeBSD$

PORTNAME=	Data-Localize
PORTVERSION=	0.00025
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for alternate data localization API

RUN_DEPENDS=	\
	p5-Moo>=1.000008:${PORTSDIR}/devel/p5-Moo \
	p5-MooX-Types-MooseLike>0:${PORTSDIR}/devel/p5-MooX-Types-MooseLike \
	p5-Log-Minimal>=0.14:${PORTSDIR}/devel/p5-Log-Minimal
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=	perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS=	p5-Test-Simple>=0.98:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
