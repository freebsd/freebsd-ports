# New ports collection makefile for:	p5-GD-Graph
# Version required:			1.24
# Date created:				21 February 2000
# Whom:	      				Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

DISTNAME=	GDGraph-1.24
PKGNAME=	p5-GD-Graph-1.24
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GD

MAINTAINER=	dima@Chg.RU

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/GD/Text/Align.pm:${PORTSDIR}/graphics/p5-GD-TextUtil

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		GD::Graph.3 GD::Graph::colour.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
