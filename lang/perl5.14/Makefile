# New ports collection makefile for:	perl5
# Version required:	5.003
# Date created:		16 April 1995
# Whom:			markm
#
# $Id: Makefile,v 1.9 1996/03/18 01:01:44 asami Exp $
#

DISTNAME=	perl5.003
PKGNAME=	perl-5.003
CATEGORIES+=	lang devel
MASTER_SITES=	ftp://ftp.funet.fi/pub/languages/perl/CPAN/src/5.0/ \
		ftp://ftp.is.co.za/pub/perl/CPAN/src/5.0/ \
		ftp://dong.math.ncu.edu.tw/perl/CPAN/src/5.0/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/src/5.0/ \
		ftp://ftp.pasteur.fr/pub/computing/unix/perl/CPAN/src/5.0/ \
		ftp://ftp.sunet.se/pub/lang/perl/CPAN/src/5.0/ \
		ftp://ftp.switch.ch/mirror/CPAN/src/5.0/ \
		ftp://unix.hensa.ac.uk/mirrors/perl-CPAN/src/5.0/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/src/5.0/ \
		ftp://ftp.delphi.com/pub/mirrors/packages/perl/CPAN/src/5.0/ \
		ftp://uiarchive.cso.uiuc.edu/pub/lang/perl/CPAN/src/5.0/

MAINTAINER=	markm@FreeBSD.ORG

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=		-sde -Dprefix=${PREFIX}

PERLMAN= "" book bot call data debug diag embed form func guts ipc lol mod \
	obj op ovl pod re ref run sec style sub syn tie toc trap var xs \
	xstut

test:
	@(cd ${WRKSRC}; make test)


post-install:
.if !defined(NOMANCOMPRESS)
	@for m in ${PERLMAN}; do gzip -9nf ${PREFIX}/man/man1/perl$$m.1; done
	@gzip -9nf ${PREFIX}/man/man1/a2p.1
	@gzip -9nf ${PREFIX}/man/man1/s2p.1
.endif
	@strip ${PREFIX}/bin/perl ${PREFIX}/bin/suidperl

.include <bsd.port.mk>
