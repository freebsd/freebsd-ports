# New ports collection makefile for:	p5-File-MMagic
# Version required:	1.02
# Date created:		25 February 2000
# Whom:	      		Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

DISTNAME=	File-MMagic-1.02
PKGNAME=	p5-File-MMagic-1.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/K/KN/KNOK

MAINTAINER=	knu@idaemons.org

USE_PERL5=	YES

MAN3=		File::MMagic.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
