# New ports collection makefile for:	devel/p5-Every
# Date created:				05 September 2008
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Every
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/T/TE/TEODOR
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Return true every N cycles or S seconds

BUILD_DEPENDS=	p5-Devel-Callsite>0:${PORTSDIR}/devel/p5-Devel-Callsite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Every.3

.include <bsd.port.mk>
