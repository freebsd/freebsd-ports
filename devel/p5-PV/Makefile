# New ports collection makefile for:	p5-PV
# Version required:			1.0
# Date created:				April 18th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	perlvision
PKGNAME=	p5-PV-1.0
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	PV
EXTRACT_SUFX=	.tgz

MAINTAINER=	jfitz@FreeBSD.org

RUN_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/i386-freebsd/Curses.pm:${PORTSDIR}/devel/p5-Curses

USE_PERL5=	YES

NO_WRKSUBDIR=	YES
NO_BUILD=	YES

do-install:
	${MKDIR} -m 755 ${PREFIX}/lib/perl5/site_perl/${PERL_VER}
	${INSTALL_DATA} ${WRKDIR}/PV.pm ${PREFIX}/lib/perl5/site_perl/${PERL_VER}
	${INSTALL_DATA} ${WRKDIR}/PerlVision.doc ${PREFIX}/lib/perl5/site_perl/${PERL_VER}

.include <bsd.port.mk>
