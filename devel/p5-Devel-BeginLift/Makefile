# $FreeBSD$

PORTNAME=	Devel-BeginLift
PORTVERSION=	0.001003
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to make selected sub calls evaluate at compile time

BUILD_DEPENDS=	${RUN_DEPENDS} \
	p5-ExtUtils-Depends>0:devel/p5-ExtUtils-Depends
RUN_DEPENDS=	\
	p5-B-Hooks-OP-Check-EntersubForCV>=0.03:devel/p5-B-Hooks-OP-Check-EntersubForCV

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 502501
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-BeginLift.xs
.endif

.include <bsd.port.post.mk>
