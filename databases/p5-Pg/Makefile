# New ports collection makefile for:	p5-Pg
# Version required:			1.5.4
# Date created:				October 19th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.8 1997/05/29 14:23:50 jfitz Exp $
#

DISTNAME=	pg95perl5-1.5.4
PKGNAME=	p5-Pg-1.5.4
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Pg

MAINTAINER=	jfitz@FreeBSD.ORG

WRKSRC=		${WRKDIR}/pg95perl5

BUILD_DEPENDS= 	perl5.004:${PORTSDIR}/lang/perl5 \
		${PREFIX}/pgsql/lib/libpq.a:${PORTSDIR}/databases/postgresql
RUN_DEPENDS=	perl5.004:${PORTSDIR}/lang/perl5

MAN3=		Pg.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
