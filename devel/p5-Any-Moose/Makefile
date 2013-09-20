# $FreeBSD$

PORTNAME=	Any-Moose
PORTVERSION=	0.21
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SARTAK
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for/to use Moose or Mouse modules

#TEST_DEPENDS=	p5-Moose>0:${PORTSDIR}/devel/p5-Moose

USES=		perl5
USE_PERL5=	configure

MAN3=	Any::Moose.3

OPTIONS_DEFINE=	MOOSE MOUSE
OPTIONS_DEFAULT=	MOUSE
MOOSE_DESC=	Use Moose
MOUSE_DESC=	Use Mouse

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMOOSE}
BUILD_DEPENDS+=	p5-Moose>0:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS+=	p5-Moose>0:${PORTSDIR}/devel/p5-Moose
.endif

.if ${PORT_OPTIONS:MMOUSE}
BUILD_DEPENDS+=	p5-Mouse>=0.40:${PORTSDIR}/devel/p5-Mouse
RUN_DEPENDS+=	p5-Mouse>=0.40:${PORTSDIR}/devel/p5-Mouse
.endif

.include <bsd.port.mk>
