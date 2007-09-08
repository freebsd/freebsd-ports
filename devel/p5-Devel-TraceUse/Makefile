# New ports collection makefile for:   devel/p5-Devel-TraceUse
# Date created:                                20 September 2006
# Whom:                                        Mauricio Herrera Cuadra <mauricio@arareko.net>
#
# $FreeBSD$
#

PORTNAME=	Devel-TraceUse
PORTVERSION=	1.00
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel
PKGNAMEPREFIX=	p5-

MAINTAINER=	mauricio@arareko.net
COMMENT=	This module shows the modules your program loads, recursively

PERL_DEPENDS=	p5-Time-HiRes>0:${PORTSDIR}/devel/p5-Time-HiRes
BUILD_DEPENDS=	${PERL_DEPENDS}
RUN_DEPENDS=	${PERL_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Devel::TraceUse.3

.include <bsd.port.mk>
