# New ports collection makefile for:	p5-Image-Size
# Version required:			2.7
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.15 1998/10/12 02:59:12 jseger Exp $
#

DISTNAME=	Image-Size-2.7
PKGNAME=	p5-Image-Size-2.7
CATEGORIES=	graphics www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Image

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 300000
BROKEN=         perl paths
.endif

MAN1=		imgsize.1
MAN3=		Image::Size.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.post.mk>
