# New ports collection makefile for:	p5-GD-Graph
# Date created:				10 April 2000
# Whom:	      				Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	GD-Graph3d
PORTVERSION=	0.55
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GD
PKGNAMEPREFIX=	p5-
DISTNAME=	GDGraph3d-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		GD::Graph3d.3

.include <bsd.port.mk>
