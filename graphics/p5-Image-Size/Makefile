# New ports collection makefile for:	p5-Image-Size
# Version required:			1.2
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.5 1997/02/25 16:04:12 jfitz Exp $
#

DISTNAME=	Image-Size-1.2
PKGNAME=	p5-Image-Size-1.2
CATEGORIES=	graphics www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Image

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	${PREFIX}/lib/perl5/IO.pm:${PORTSDIR}/net/p5-IO \
		perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

MAN1=		imgsize.1
MAN3=		Image::Size.3
MAN3PREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
