# New ports collection makefile for:	p5-File-Tools
# Version required:			2.0
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.4 1997/04/20 13:52:11 wosch Exp $
#

DISTNAME=	File-Tools-2.0
PKGNAME=	p5-File-Tools-2.0
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.004:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.004:${PORTSDIR}/lang/perl5

MAN3=		File::Tools.3 File::Recurse.3 File::Copy.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
