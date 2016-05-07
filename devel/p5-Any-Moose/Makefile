# $FreeBSD$

PORTNAME=	Any-Moose
PORTVERSION=	0.26
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ETHER
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for/to use Moose or Mouse modules

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

#TEST_DEPENDS=	p5-Moose>0:devel/p5-Moose

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

OPTIONS_DEFINE=	MOOSE MOUSE
OPTIONS_DEFAULT=	MOUSE
MOOSE_DESC=	Use Moose
MOUSE_DESC=	Use Mouse

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMOOSE}
BUILD_DEPENDS+=	p5-Moose>0:devel/p5-Moose
RUN_DEPENDS+=	p5-Moose>0:devel/p5-Moose
.endif

.if ${PORT_OPTIONS:MMOUSE}
BUILD_DEPENDS+=	p5-Mouse>=0.40:devel/p5-Mouse
RUN_DEPENDS+=	p5-Mouse>=0.40:devel/p5-Mouse
.endif

.include <bsd.port.mk>
