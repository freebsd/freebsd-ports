# New ports collection makefile for:	p5-Image-Size
# Version required:			1.2
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.1.1.1 1996/10/24 08:20:02 jfitz Exp $
#

DISTNAME=	Image-Size-1.2
PKGNAME=	p5-Image-Size-1.2
CATEGORIES+=	graphics www
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/Image/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/Image/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/Image/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/Image/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/Image/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/Image/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
.if !defined(NOMANCOMPRESS)
		@ for file in Image::Size; do \
			gzip -9nf ${PREFIX}/lib/perl5/man/man3/$$file.3; \
		done
		@ for file in imgsize; do \
			gzip -9nf ${PREFIX}/man/man1/$$file.1; \
		done
.endif

.include <bsd.port.mk>
