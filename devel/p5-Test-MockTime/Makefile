# New ports collection makefile for:	devel/p5-Test-MockTime
# Date created:				1 Aug 2006
# Whom:					Timur I. Bakeyev <bat@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	Test-MockTime
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	timur@FreeBSD.org
COMMENT=	Replaces actual time with simulated time

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Time/Piece.pm:${PORTSDIR}/devel/p5-Time-Piece
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Time/Piece.pm:${PORTSDIR}/devel/p5-Time-Piece

PERL_CONFIGURE=	yes

MAN3=		Test::MockTime.3

.include <bsd.port.mk>
