# New ports collection makefile for:	p5-BSD-Resource
# Version required:			1.0701
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	BSD-Resource-1.0701
PKGNAME=	p5-BSD-Resource-1.0701
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	BSD

MAINTAINER=	jfitz@FreeBSD.org

USE_PERL5=	YES

MAN3=		BSD::Resource.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
