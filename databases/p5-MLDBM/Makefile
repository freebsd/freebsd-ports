# New ports collection makefile for:    p5-MLDBM
# Version required:                     2.00
# Date created:                         December 3 1997
# Whom:                                 ache@freebsd.org
#
# $Id: Makefile,v 1.5 1998/08/19 09:47:25 asami Exp $
#

DISTNAME=       MLDBM-2.00
PKGNAME=        p5-MLDBM-2.00
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=     MLDBM

MAINTAINER=     ports@FreeBSD.ORG

BUILD_DEPENDS= 	${PREFIX}/lib/perl5/site_perl/FreezeThaw.pm:${PORTSDIR}/devel/p5-FreezeThaw \
		${PREFIX}/lib/perl5/site_perl/Storable.pm:${PORTSDIR}/devel/p5-Storable

USE_PERL5=	YES

MAN3=           MLDBM.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
