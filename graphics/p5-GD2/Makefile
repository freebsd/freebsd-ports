# New ports collection makefile for:    p5-GD2
# Date created:				March 11, 2003
# Whom:	      				Philip M. Gollucci <philip@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	GD2
PORTVERSION=	2.06
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GD
PKGNAMEPREFIX=	p5-
DISTNAME=	GD-${PORTVERSION}

MAINTAINER=	philip@p6m7g8.com
COMMENT=	A perl5 interface to Gd Graphics Library version2

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd2

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		GD.3 GD::Polyline.3

.include <bsd.port.mk>
