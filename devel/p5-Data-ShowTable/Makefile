# New ports collection makefile for:    p5-Data-ShowTable
# Version required:			3.3
# Date created:				September 10th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.6 1998/10/12 04:19:27 jseger Exp $
#

DISTNAME=	Data-ShowTable-3.3
PKGNAME=	p5-Data-ShowTable-3.3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 300000
BROKEN=         perl
.endif

MAN1=		showtable.1
MAN3=		Data::ShowTable.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.post.mk>
