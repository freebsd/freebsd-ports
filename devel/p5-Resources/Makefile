# New ports collection makefile for:	p5-Resources
# Version required:			1.03
# Date created:				October 24th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.2 1996/10/24 09:58:34 jfitz Exp $
#

DISTNAME=	Resources-1.03
PKGNAME=	p5-Resources-1.03
CATEGORIES+=	devel
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/Resources/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/Resources/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/Resources/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/Resources/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/Resources/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/Resources/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
.if !defined(NOMANCOMPRESS)
		@ for file in Resources; do \
			gzip -9nf ${PREFIX}/lib/perl5/man/man3/$$file.3; \
		done
.endif     

.include <bsd.port.mk>
