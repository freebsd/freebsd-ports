# New ports collection makefile for:	perl5
# Version required:	5.002
# Date created:		16 April 1995
# Whom:			markm
#
# $Id$
#

DISTNAME=		perl5.002
PKGNAME=		perl-5.002
CATEGORIES+=            lang devel
MASTER_SITES=           ftp://ftp.netlabs.com/pub/outgoing/perl5.0/ ftp://ftp.wpi.edu/perl5/

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
	@for m in ${PERLMAN}; do gzip -9nf ${PREFIX}/man/man1/perl$$m.1; done
	@gzip -9nf ${PREFIX}/man/man1/a2p.1
	@gzip -9nf ${PREFIX}/man/man1/s2p.1
	@strip ${PREFIX}/bin/perl ${PREFIX}/bin/suidperl

.include <bsd.port.mk>
