# New ports collection makefile for:	p5-Carp-Datum
# Date created:				Aug 5th 2002
# Whom:	      				kuriyama
#
# $FreeBSD$
#

PORTNAME=	Carp-Datum
PORTVERSION=	0.1.3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Carp
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Debugging And Tracing Ultimate Module

BUILD_DEPENDS=	${PM_BASE}/Log/Agent.pm:${PORTSDIR}/devel/p5-Log-Agent \
		${PM_BASE}/Getargs/Long.pm:${PORTSDIR}/devel/p5-Getargs-Long
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
PM_BASE=	${SITE_PERL}

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN1=		datum_strip.1
MAN3=		Carp::Datum::Assert.3 \
		Carp::Datum.3 \
		Carp::Datum::Strip.3 \
		Carp::Datum::MakeMaker.3 \
		Carp::Datum::Cfg.3 \
		Carp::Datum::Flags.3

.include <bsd.port.mk>
