# New ports collection makefile for:	p5-C-Scan
# Version required:			0.5
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.10 1998/04/04 13:55:57 vanilla Exp $
#

DISTNAME=	C-Scan-0.5
PKGNAME=	p5-C-Scan-0.5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	C

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Data/Flow.pm:${PORTSDIR}/devel/p5-Data-Flow

USE_PERL5=	YES

MAN3=		C::Scan.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
