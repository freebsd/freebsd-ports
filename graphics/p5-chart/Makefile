# New ports collection makefile for:	p5-chart
# Version required:	0.94
# Date Created:		8 April 1998
# Whom:			Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1998/08/19 12:38:40 vanilla Exp $
#

DISTNAME=	chart-0.94
PKGNAME=	p5-chart-0.94
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Chart

MAINTAINER=	ports@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/i386-freebsd/GD.pm:${PORTSDIR}/graphics/p5-GD

WRKSRC=		${WRKDIR}/Chart-0.94

USE_PERL5=	YES

MAN3=		Chart.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
