# New ports collection makefile for:    p5-Msql
# Version required:			1.11
# Date created:				September 29th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.4 1996/11/17 03:18:38 obrien Exp $
#

DISTNAME=	MsqlPerl-1.11
PKGNAME=	p5-Msql-1.11
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Msql

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	${PREFIX}/Minerva/lib/libmsql.a:${PORTSDIR}/databases/msql \
		perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

MAN1=		pmsql.1

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:	
.if !defined(NOMANCOMPRESS)
		@ for file in ${PREFIX}/lib/perl5/man/man3/Msql.3; do \
			gzip -9nf $$file; \
		done
.endif

.include <bsd.port.mk>
