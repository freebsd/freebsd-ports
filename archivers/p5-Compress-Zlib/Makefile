# New ports collection makefile for:	p5-Compress-Zlib
# Version required:			0.4
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.1.1.1 1996/10/23 23:51:34 jfitz Exp $
#

DISTNAME=	Compress-Zlib-0.4
PKGNAME=	p5-Compress-Zlib-0.4
CATEGORIES+=	archivers
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/Compress/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/Compress/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/Compress/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/Compress/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/Compress/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/Compress/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
.if !defined(NOMANCOMPRESS)
		@ for file in Compress::Zlib; do \
			gzip -9nf ${PREFIX}/lib/perl5/man/man3/$$file.3; \
		done
.endif

.include <bsd.port.mk>
