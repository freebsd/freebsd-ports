# New ports collection makefile for:	p5-Curses
# Version required:			1.0
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.1.1.1 1996/10/24 07:57:07 jfitz Exp $
#

DISTNAME=	Curses-1.0
PKGNAME=	p5-Curses-1.0
CATEGORIES+=	devel
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/Curses/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/Curses/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/Curses/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/Curses/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/Curses/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/Curses/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

pre-configure:
		@ ln -s ${WRKSRC}/hints/c-freebsd.ncurses.h ${WRKSRC}/c-config.h

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
.if !defined(NOMANCOMPRESS)
		@ for file in Curses; do \
			gzip -9nf ${PREFIX}/lib/perl5/man/man3/$$file.3; \
		done
.endif

.include <bsd.port.mk>
