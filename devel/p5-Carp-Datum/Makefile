# Created by: kuriyama
# $FreeBSD$

PORTNAME=	Carp-Datum
PORTVERSION=	0.1.3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Debugging And Tracing Ultimate Module

BUILD_DEPENDS=	p5-Log-Agent>=0:${PORTSDIR}/devel/p5-Log-Agent \
		p5-Getargs-Long>=0:${PORTSDIR}/devel/p5-Getargs-Long
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		datum_strip.1
MAN3=		Carp::Datum::Assert.3 \
		Carp::Datum.3 \
		Carp::Datum::Strip.3 \
		Carp::Datum::MakeMaker.3 \
		Carp::Datum::Cfg.3 \
		Carp::Datum::Flags.3

.include <bsd.port.mk>
