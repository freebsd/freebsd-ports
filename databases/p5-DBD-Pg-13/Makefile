# New ports collection makefile for:    p5-DBD-Pg
# Date created:				June 17th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBD-Pg
PORTVERSION=	0.93
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	jfitz@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
LIB_DEPENDS=	pq.2:${PORTSDIR}/databases/postgresql

USE_PERL5=	yes
MAKE_ENV=	POSTGRES_INCLUDE=${PREFIX}/pgsql/include POSTGRES_LIB=${PREFIX}/pgsql/lib

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		DBD::Pg.3 DBD::dbd-pg.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
			CC="${CC}" CCFLAGS="${CFLAGS}"

.include <bsd.port.mk>
