# New ports collection makefile for:	perl5
# Version required:	5.001
# Date created:		16 April 1995
# Whom:			markm
#
# $Id: Makefile,v 1.2 1995/04/18 02:00:15 asami Exp $
#

DISTNAME=		perl5.001
PKGNAME=		perl-5.001
CATEGORIES+=            languages development programming
MASTER_SITES=           ftp://prep.ai.mit.edu/pub/gnu/ ftp://ftp.sun.ac.za/pub/gnu/
EXTRACT_SUFX=		.tar.gz

MAINTAINER=	markm@FreeBSD.ORG

#
# This isn't really interactive, but the Configure script checks for
# file descriptor 0, so it won't run if you </dev/null to run a
# nightly batch build....
#
IS_INTERACTIVE=		yes

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=		-sde

test:
	@(cd ${WRKSRC}; make test)

.include <bsd.port.mk>
