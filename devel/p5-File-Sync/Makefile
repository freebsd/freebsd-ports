# New ports collection makefile for:	p5-File-Sync
# Version required:	0.06
# Date created:		6 March 1998
# Whom:			Jun Kuriyama <kuriyama@opt.phys.waseda.ac.jp>
#
# $FreeBSD$
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
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
