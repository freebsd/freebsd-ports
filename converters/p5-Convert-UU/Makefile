# New ports collection makefile for:	p5-Convert-UU
# Version required:			0.01
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.2 1996/10/24 09:58:09 jfitz Exp $
#

DISTNAME=	Convert-UU-0.01
PKGNAME=	p5-Convert-UU-0.1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/Convert/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/Convert/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/Convert/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/Convert/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/Convert/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/Convert/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
.if !defined(NOMANCOMPRESS)
		@ for file in Convert::UU; do \
			gzip -9nf ${PREFIX}/lib/perl5/man/man3/$$file.3; \
		done
		@ for file in puuencode puudecode; do \
			gzip -9nf ${PREFIX}//man/man1/$$file.1; \
		done
.endif

.include <bsd.port.mk>
