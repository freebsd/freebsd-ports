# New ports collection makefile for:	p5-Ioctl
# Version required:			0.7
# Date created:				October 21st 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.6 1997/05/24 13:17:07 jfitz Exp $
#

DISTNAME=	Ioctl-0_7
PKGNAME=	p5-Ioctl-0.7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Ioctl

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
