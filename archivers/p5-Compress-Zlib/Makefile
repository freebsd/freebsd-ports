# New ports collection makefile for:	p5-Compress-Zlib
# Version required:			1.01
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	Compress-Zlib-1.01
PKGNAME=	p5-Compress-Zlib-1.01
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Compress

MAINTAINER=	jfitz@FreeBSD.org

USE_PERL5=	YES

MAN3=		Compress::Zlib.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
