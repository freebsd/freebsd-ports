# New ports collection makefile for:	p5-Resources
# Version required:			1.04
# Date created:				October 24th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.5 1997/04/20 21:26:20 jfitz Exp $
#

DISTNAME=	Resources-1.04
PKGNAME=	p5-Resources-1.04
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Resources

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.004:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.004:${PORTSDIR}/lang/perl5

MAN3=		Resources.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
