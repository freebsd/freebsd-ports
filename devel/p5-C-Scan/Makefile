# New ports collection makefile for:	p5-C-Scan
# Version required:			0.3
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.4 1996/10/24 11:18:40 asami Exp $
#

DISTNAME=	C-Scan-0.3
PKGNAME=	p5-C-Scan-0.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	C

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5 \
		${PREFIX}/lib/perl5/site_perl/Data/Flow.pm:${PORTSDIR}/devel/p5-Data-Flow
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

MAN3=		C::Scan.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
