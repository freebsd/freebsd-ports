# New ports collection makefile for:	p5-Ioctl
# Version required:			0.7
# Date created:				October 21st 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.2 1996/10/24 09:59:14 jfitz Exp $
#

DISTNAME=	Ioctl-0_7
PKGNAME=	p5-Ioctl-0.7
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/Ioctl/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/Ioctl/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/Ioctl/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/Ioctl/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/Ioctl/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/Ioctl/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
