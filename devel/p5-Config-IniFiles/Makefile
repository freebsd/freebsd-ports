# New ports collection makefile for:	p5-IniConf
# Version required:			0.91
# Date created:				October 21st 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.5 1997/05/24 13:17:03 jfitz Exp $
#

DISTNAME=	IniConf.pm-0.91
PKGNAME=	p5-IniConf-0.91
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IniConf

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MAN3=		IniConf.pm.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
