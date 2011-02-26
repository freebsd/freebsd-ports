# New ports collection makefile for:	devel/p5-VCP-Source-cvsbk
# Date created:				Sep 1 2004
# Whom:					June-Yen Huang <jihuang@gate.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	VCP-Source-cvsbk
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/C/CL/CLKAO
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VCP source driver for bk exported cvs repository

BUILD_DEPENDS=	${SITE_PERL}/VCP.pm:${PORTSDIR}/devel/p5-VCP-autrijus
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		VCP::Source::cvsbk.3 \
		VCP::Filter::cvsbkchangeset.3

.include <bsd.port.mk>
