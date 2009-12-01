# New ports collection makefile for:	Audio
# Date created:				15 September 2003
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Audio
PORTVERSION=	1.029
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	An audio manipulation routines for perl

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Math/GSL.pm:${PORTSDIR}/math/p5-Math-GSL
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Audio::Play.3 Audio::Data.3

.include <bsd.port.mk>
