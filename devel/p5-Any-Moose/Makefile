# $FreeBSD$

PORTNAME=	Any-Moose
PORTVERSION=	0.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SARTAK
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for/to use Moose or Mouse modules

#TEST_DEPENDS=	p5-Moose>0:${PORTSDIR}/devel/p5-Moose

PERL_CONFIGURE=	yes

MAN3=	Any::Moose.3

OPTIONS=	MOOSE "Use Moose" off \
		MOUSE "Use Mouse" on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_MOOSE)
BUILD_DEPENDS+=	p5-Moose>0:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS+=	p5-Moose>0:${PORTSDIR}/devel/p5-Moose
.endif

.if defined(WITH_MOUSE)
BUILD_DEPENDS+=	p5-Mouse>=0.40:${PORTSDIR}/devel/p5-Mouse
RUN_DEPENDS+=	p5-Mouse>=0.40:${PORTSDIR}/devel/p5-Mouse
.endif

.include <bsd.port.mk>
