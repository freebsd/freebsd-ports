# New ports collection makefile for:	p5-File-BasicFlock
# Version required:			96.072401
# Date created:				
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.7 1998/08/12 09:57:50 asami Exp $
#

DISTNAME=	File-BasicFLock-96.072401
PKGNAME=	p5-File-BasicFlock-96.072401
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MAN3=		File::BasicFlock.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
