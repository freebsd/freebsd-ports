# New ports collection makefile for:	p5-Time-HiRes
# Version required:		1.20
# Date created:			13 June 1999
# Whom:				Stephen J. Roznowski <sjr@home.net>
#
# $FreeBSD$
#

DISTNAME=	Time-HiRes-01.20
PKGNAME=	p5-Time-HiRes-01.20
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Time

MAINTAINER=	ports@FreeBSD.org

USE_PERL5=	yes

MAN3=		Time::HiRes.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
