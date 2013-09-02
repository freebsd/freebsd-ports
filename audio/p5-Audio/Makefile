# New ports collection makefile for:	Audio
# Date created:				15 September 2003
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Audio
PORTVERSION=	1.029
PORTREVISION=	2
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Audio manipulation routines for perl

BUILD_DEPENDS=	p5-Math-GSL>=0:${PORTSDIR}/math/p5-Math-GSL
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Audio::Play.3 Audio::Data.3

.include <bsd.port.mk>
