# New ports collection makefile for:    p5-MLDBM
# Version required:                     1.25
# Date created:                         December 3 1997
# Whom:                                 ache@freebsd.org
#
# $Id: Makefile,v 1.2 1997/12/03 14:02:07 ache Exp $
#

DISTNAME=       MLDBM-1.25
PKGNAME=        p5-MLDBM-1.25
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=     MLDBM

MAINTAINER=     ports@FreeBSD.ORG

BUILD_DEPENDS= 	${PREFIX}/lib/perl5/site_perl/Data/Dumper.pm:${PORTSDIR}/devel/p5-Data-Dumper

USE_PERL5=	YES

MAN3=           MLDBM.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
