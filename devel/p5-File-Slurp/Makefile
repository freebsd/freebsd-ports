# New ports collection makefile for:	p5-File-Slurp
# Version required:			96.042202
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id$
#

DISTNAME=	File-Slurp-96.042202
PKGNAME=	p5-File-Slurp-96.042202
CATEGORIES+=	devel
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/File/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/File/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/File/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/File/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/File/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/File/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
.if !defined(NOMANCOMPRESS)
		@ for file in File::Slurp; do \
			gzip -9nf ${PREFIX}/lib/perl5/man/man3/$$file.3; \
		done
.endif

.include <bsd.port.mk>
