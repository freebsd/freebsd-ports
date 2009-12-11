# New ports collection makefile for:	p5-B-Utils
# Date created:				31 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	B-Utils
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Helper functions for op tree manipulation

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0.302:${PORTSDIR}/devel/p5-ExtUtils-Depends
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		B::Utils.3 B::Utils::OP.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
