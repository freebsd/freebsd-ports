# New ports collection makefile for:	p5-Geo-Proj4
# Date created:      			27 January 2006
# Whom:					Eric Stith
#
# $FreeBSD$
#

PORTNAME=	Geo-Proj4
PORTVERSION=	0.96
CATEGORIES=	graphics devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Geo
PKGNAMEPREFIX=	p5-

MAINTAINER=	estith.freebsd.ports@thelunarempire.net
COMMENT=	Perl cartographic projections wrapper for Proj library

LIB_DEPENDS=	proj:${PORTSDIR}/graphics/proj

MAN3=		Geo::Proj4.3
CFLAGS+=	-I ${PREFIX}/include	# XXX - This seems ugly
PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
