# New ports collection makefile for:	devel/p5-B-Generate
# Date created:				26 February 2007
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	B-Generate
PORTVERSION=	1.39
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Create your own Perl op trees

COMMON_DEPENDS=	p5-ExtUtils-CBuilder>=0:${PORTSDIR}/devel/p5-ExtUtils-CBuilder
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	B::Generate.3

.include <bsd.port.mk>
