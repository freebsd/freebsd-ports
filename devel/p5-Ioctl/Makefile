# New ports collection makefile for:	p5-Ioctl
# Version required:			0.7
# Date created:				October 21st 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.5 1997/04/20 21:26:16 jfitz Exp $
#

DISTNAME=	Ioctl-0_7
PKGNAME=	p5-Ioctl-0.7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Ioctl

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.004:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.004:${PORTSDIR}/lang/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
