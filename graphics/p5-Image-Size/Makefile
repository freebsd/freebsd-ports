# New ports collection makefile for:	p5-Image-Size
# Version required:			1.2
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.2 1996/10/24 09:58:59 jfitz Exp $
#

DISTNAME=	Image-Size-1.2
PKGNAME=	p5-Image-Size-1.2
CATEGORIES=	graphics www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Image

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
