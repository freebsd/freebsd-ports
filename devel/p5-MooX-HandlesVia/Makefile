# $FreeBSD$

PORTNAME=	MooX-HandlesVia
PORTVERSION=	0.001005
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	NativeTrait-like behavior for Moo

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moo>=1.001000:${PORTSDIR}/devel/p5-Moo \
		p5-MooX-Types-MooseLike>=0:${PORTSDIR}/devel/p5-MooX-Types-MooseLike \
		p5-Data-Perl>=0.002006:${PORTSDIR}/devel/p5-Data-Perl
TEST_DEPENDS=	p5-MooX-Types-MooseLike>=0:${PORTSDIR}/devel/p5-MooX-Types-MooseLike \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-bareword-filehandles>=0:${PORTSDIR}/devel/p5-bareword-filehandles \
		p5-indirect>=0:${PORTSDIR}/devel/p5-indirect \
		p5-multidimensional>=0:${PORTSDIR}/devel/p5-multidimensional
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
