# New ports collection makefile for:	p5-IO-Stty
# Version required:	0.02
# Date created:		14 Jan 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	IO-Stty-.02
PKGNAME=	p5-IO-Stty-0.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IO

MAINTAINER=	andrews@technologist.com

USE_PERL5=	yes

do-configure:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL LDDLFLAGS=-shared LDFLAGS=-L/usr/lib)

.include <bsd.port.mk>
