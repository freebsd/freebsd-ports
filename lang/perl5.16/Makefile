# New ports collection makefile for:	perl5
# Version required:	5.001
# Date created:		16 April 1995
# Whom:			markm
#
# $Id: Makefile,v 1.8 1995/04/15 05:44:51 asami Exp $
#

DISTNAME=		perl5.001
PKGNAME=		perl-5.001
CATEGORIES+=		languages
MASTER_SITES=		ftp://ftp.sun.ac.za/pub/gnu/
EXTRACT_SUFX=		.tar.gz

MAINTAINER=	markm@FreeBSD.ORG

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=		-sde

test:
	@(cd ${WRKSRC}; make test)

.include <bsd.port.mk>
