# New ports collection makefile for:	perl5
# Version required:	5.001
# Date created:		16 April 1995
# Whom:			markm
#
# $Id: Makefile,v 1.4 1995/04/23 17:21:34 jmz Exp $
#

DISTNAME=		perl5.001
PKGNAME=		perl-5.001
CATEGORIES+=            languages development programming
MASTER_SITES=           ftp://prep.ai.mit.edu/pub/gnu/ ftp://ftp.sun.ac.za/pub/gnu/
EXTRACT_SUFX=		.tar.gz

MAINTAINER=	markm@FreeBSD.ORG

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=		-sde -Dprefix=${PREFIX}

PERLMAN= "" api book bot call data debug diag embed form func guts ipc mod \
	   obj op ovl pod re ref run sec style sub syn trap var

test:
	@(cd ${WRKSRC}; make test)


post-install:
	@for m in ${PERLMAN}; do gzip -9nf ${PREFIX}/man/man1/perl$$m.1; done
	@gzip -9nf ${PREFIX}/man/man1/a2p.1
	@gzip -9nf ${PREFIX}/man/man1/s2p.1
	@strip ${PREFIX}/bin/perl ${PREFIX}/bin/suidperl

.include <bsd.port.mk>
