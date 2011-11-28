# New ports collection makefile for:	p5-B-Utils
# Date created:				31 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	B-Utils
PORTVERSION=	0.17
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JJORE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Helper functions for op tree manipulation

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0.301:${PORTSDIR}/devel/p5-ExtUtils-Depends

MAN3=		B::Utils.3 B::Utils::OP.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-ExtUtils-CBuilder>=0:${PORTSDIR}/devel/p5-ExtUtils-CBuilder
.endif

.include <bsd.port.post.mk>
