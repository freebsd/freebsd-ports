# New ports collection makefile for:	p5-Geo-Proj4
# Date created:      			27 January 2006
# Whom:					Eric Stith
#
# $FreeBSD$
#

PORTNAME=	Geo-Proj4
PORTVERSION=	1.01
CATEGORIES=	graphics devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Perl cartographic projections wrapper for Proj library

LIB_DEPENDS=	proj:${PORTSDIR}/graphics/proj

MAN3=		Geo::Proj4.3
CONFIGURE_ENV=	GEOPROJ_FWTOOLS_DIR=${LOCALBASE}
MAKE_ENV=	INC=-I${LOCALBASE}/include
PERL_CONFIGURE=	yes

.include <bsd.port.mk>
