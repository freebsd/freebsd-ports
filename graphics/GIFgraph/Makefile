# New ports collection makefile for:	p5-GIFgraph
# Version required:			1.01
# Date created:				Nov 9, 1998
# Whom:					laskavy@gambit.msk.su
#
# $FreeBSD$
#

DISTNAME=	GIFgraph-1.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GIFgraph

MAINTAINER=	laskavy@gambit.msk.su

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/i386-freebsd/GD.pm:${PORTSDIR}/graphics/p5-GD

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		GIFgraph.3 GIFgraph::colour.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
