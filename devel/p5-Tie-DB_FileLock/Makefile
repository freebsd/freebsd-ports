# New ports collection makefile for:	p5-Tie-DB_FileLock
# Date created:				August 17 2000
# Whom:	      				Josh Tiefenbach <josh@zipperup.org>
#
# $FreeBSD$
#

PORTNAME=	Tie-DB_FileLock
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tie
PKGNAMEPREFIX=	p5-

MAINTAINER=	josh@zipperup.org

USE_PERL5=	yes

MAN3=			Tie::DB_FileLock.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
			CC="${CC}" CCFLAGS="${CFLAGS}"

.include <bsd.port.mk>
