# New ports collection makefile for:	p5-GD-Graph
# Date created:				10 April 2000
# Whom:	      				Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	GD-Graph3d
PORTVERSION=	0.40
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GD
DISTNAME=	GDGraph3d-${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	dima@Chg.RU

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph

USE_PERL5=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		GD::Graph::Graph3d.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
