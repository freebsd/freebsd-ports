# New ports collection makefile for:	p5-File-Sync
# Version required:	0.06
# Date created:		6 March 1998
# Whom:			Jun Kuriyama <kuriyama@opt.phys.waseda.ac.jp>
#
# $Id: Makefile,v 1.2 1998/03/21 02:06:11 asami Exp $
#

DISTNAME=	File-Sync-0.06
PKGNAME=	p5-File-Sync-0.06
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File

MAINTAINER=	kuriyama@opt.phys.waseda.ac.jp

USE_PERL5=	YES

MAN3=		File::Sync.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
