# New ports collection makefile for:	p5-BSD-Resource
# Version required:			1.03
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id$
#

DISTNAME=	BSD-Resource-1.03
PKGNAME=	p5-BSD-Resource-1.03
CATEGORIES+=	devel
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/BSD/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/BSD/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/BSD/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/BSD/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/BSD/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/BSD/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
.if !defined(NOMANCOMPRESS)
		@ for file in BSD::Resource; do \
			gzip -9nf ${PREFIX}/lib/perl5/man/man3/$$file.3; \
		done
.endif

.include <bsd.port.mk>
