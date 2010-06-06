# New ports collection makefile for:   devel/p5-Devel-TraceUse
# Date created:                                20 September 2006
# Whom:                                        Mauricio Herrera Cuadra <mauricio@arareko.net>
#
# $FreeBSD$
#

PORTNAME=	Devel-TraceUse
PORTVERSION=	2.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mauricio@arareko.net
COMMENT=	This module shows the modules your program loads, recursively

BUILD_DEPENDS=	p5-Time-HiRes>0:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS=	p5-Time-HiRes>0:${PORTSDIR}/devel/p5-Time-HiRes

PERL_MODBUILD=	yes

MAN3=	Devel::TraceUse.3

.include <bsd.port.mk>
