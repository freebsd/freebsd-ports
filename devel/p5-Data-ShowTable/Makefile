# New ports collection makefile for:    p5-Data-ShowTable
# Version required:			3.3
# Date created:				September 10th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.3 1998/08/06 14:59:52 vanilla Exp $
#

DISTNAME=	Data-ShowTable-3.3
PKGNAME=	p5-Data-ShowTable-3.3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MAN1=		showtable.1
MAN3=		Data::ShowTable.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
