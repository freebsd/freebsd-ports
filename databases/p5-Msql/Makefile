
# Version required:			1.11
# Date created:				September 29th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.2 1996/10/17 03:02:08 jfitz Exp $
#

DISTNAME=	MsqlPerl-1.11
PKGNAME=	p5-Msql-1.11
CATEGORIES+=	databases
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/Msql/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/Msql/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/Msql/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/Msql/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/Msql/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/Msql/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	${PREFIX}/Minerva/lib/libmsql.a:${PORTSDIR}/databases/msql \
		perl5.003:${PORTSDIR}/lang/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:	
.if !defined(NOMANCOMPRESS)
		@ for file in ${PREFIX}/man/man1/pmsql.1 ${PREFIX}/lib/perl5/man/man3/Msql.3; do \
			gzip -9nf $$file; \
		done
.endif

.include <bsd.port.mk>
