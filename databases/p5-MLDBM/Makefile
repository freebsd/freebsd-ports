# New ports collection makefile for:    p5-MLDBM
# Version required:                     1.24
# Date created:                         December 3 1997
# Whom:                                 ache@freebsd.org
#
#   $Id: Makefile,v 1.10 1997/09/13 17:53:19 jfitz Exp $
#

DISTNAME=       MLDBM-1.24
PKGNAME=        p5-${DISTNAME}
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
