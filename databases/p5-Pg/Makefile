# New ports collection makefile for:	p5-Pg
# Version required:			1.6.1
# Date created:				October 19th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	pgsql_perl5-1.8.1
PKGNAME=	p5-Pg-1.8.1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Pg

MAINTAINER=	jfitz@FreeBSD.org

BUILD_DEPENDS= 	${LOCALBASE}/pgsql/lib/libpq.a:${PORTSDIR}/databases/postgresql

USE_PERL5=	YES

POSTGRES_HOME?=	${PREFIX}/pgsql
MAKE_ENV+=	POSTGRES_HOME=${POSTGRES_HOME}

MAN3=		Pg.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
