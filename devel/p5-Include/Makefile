# New ports collection makefile for:	p5-Include
# Version required:			1.02a
# Date created:				October 21st 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id$
#

DISTNAME=	Include-1.02a
PKGNAME=	p5-Include-1.02a
CATEGORIES+=	devel
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/Include/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/Include/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/Include/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/Include/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/Include/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/Include/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
.if !defined(NOMANCOMPRESS)
		@ for file in Include; do \
			gzip -9nf ${PREFIX}/lib/perl5/man/man3/$$file.3; \
		done
.endif

.include <bsd.port.mk>
