# New ports collection makefile for:	p5-Convert-UU
# Version required:			0.01
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.3 1996/11/11 05:49:57 obrien Exp $
#

DISTNAME=	Convert-UU-0.01
PKGNAME=	p5-Convert-UU-0.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Convert

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

MAN1=		puuencode.1 puudecode.1

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
.if !defined(NOMANCOMPRESS)
	@ for file in Convert::UU; do \
		gzip -9nf ${PREFIX}/lib/perl5/man/man3/$$file.3; \
	done
.endif

.include <bsd.port.mk>
