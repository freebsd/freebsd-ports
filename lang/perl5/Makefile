# New ports collection makefile for:	perl5
# Version required:	5.003
# Date created:		16 April 1995
# Whom:			markm
#
# $Id: Makefile,v 1.11 1996/11/12 02:18:57 obrien Exp $
#

DISTNAME=	perl5.003
PKGNAME=	perl-5.003
CATEGORIES=	lang devel
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

MAN1= 	perlbook.1 perlbot.1 perlcall.1 perldata.1 perldebug.1 perldiag.1  \
	perlembed.1 perlform.1 perlfunc.1 perlguts.1 perlipc.1 perllol.1   \
	perlmod.1 perlobj.1 perlop.1 perlovl.1 perlpod.1 perlre.1 perlref.1 \
	perlrun.1 perlsec.1 perlstyle.1 perlsub.1 perlsyn.1 perltie.1  \
	perltoc.1 perltrap.1 perlvar.1 perlxs.1 perlxstut.1
MAN1+=	a2p.1 s2p.1

test:
	@(cd ${WRKSRC}; make test)


post-install:
	@strip ${PREFIX}/bin/perl ${PREFIX}/bin/suidperl

.include <bsd.port.mk>
