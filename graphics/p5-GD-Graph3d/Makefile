# New ports collection makefile for:	p5-GD-Graph
# Date created:				10 April 2000
# Whom:	      				Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	GD-Graph3d
PORTVERSION=	0.63
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GD
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Creates 3D charts with GD::Graph and GD

BUILD_DEPENDS=	${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		GD::Graph3d.3

post-patch:
# pod2man doesn't work without this
	${PERL} -pi -e 's/\r//' ${WRKSRC}/lib/GD/Graph3d.pm

.include <bsd.port.mk>
