# New ports collection makefile for:	p5-Storable
# Version required:			0.6.2
# Date created:				July 7th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.7 1998/05/14 07:52:45 vanilla Exp $
#

DISTNAME=	Storable-0.6_402
PKGNAME=	p5-Storable-0.6.2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Storable

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

WRKSRC=		${WRKDIR}/Storable-0.6@2
MANPREFIX=	${PREFIX}/lib/perl5
MAN3=		Storable.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
