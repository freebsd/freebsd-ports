# New ports collection makefile for:	p5-Storable
# Version required:			0.5.4
# Date created:				July 7th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.3 1998/04/11 14:10:36 vanilla Exp $
#

DISTNAME=	Storable-0.5@4
PKGNAME=	p5-Storable-0.5.4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Storable

MAINTAINER=	jfitz@FreeBSD.ORG

BROKEN=		fetch

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5
MAN3=		Storable.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
