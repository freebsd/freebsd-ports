# New ports collection makefile for:    p5-GD
# Version required:			1.14
# Date created:				June 26th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.ORG>
#
#   $Id: Makefile,v 1.1 1997/06/27 01:49:46 jfitz Exp $
#

DISTNAME=	GD-1.14
PKGNAME=	p5-GD-1.14
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GD

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libgd.a:${PORTSDIR}/graphics/gd

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5
MAN3=		GD.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
