# New ports collection makefile for:	p5-Time-Piece-MySQL
# Date created:		19 August 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Time-Piece-MySQL
PORTVERSION=	0.03
CATEGORIES=	databases devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Time
PKGNAMEPREFIX=	p5-

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Time::Piece::MySQL - Adds MySQL-specific methods to Time::Piece

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Time/Piece.pm:${PORTSDIR}/devel/p5-Time-Piece
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Time::Piece::MySQL.3

.include <bsd.port.mk>
