# New ports collection makefile for:	p5-IniConf
# Version required:			0.91
# Date created:				October 21st 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.2 1996/10/24 09:59:09 jfitz Exp $
#

DISTNAME=	IniConf.pm-0.91
PKGNAME=	p5-IniConf-0.91
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IniConf

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

MAN3=		IniConf.pm.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
