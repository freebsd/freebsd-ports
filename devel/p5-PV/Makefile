# New ports collection makefile for:	p5-PV
# Date created:				April 18th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PV
PORTVERSION=	1.5
CATEGORIES=	devel net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	PV
PKGNAMEPREFIX=	p5-
DISTNAME=	PerlVision-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A perl5 library for text-mode user interface widgets

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Curses.pm:${PORTSDIR}/devel/p5-Curses

USE_PERL5=	YES

NO_BUILD=	YES
PLIST_FILES=	%%SITE_PERL%%/PV.pm

do-install:
	${MKDIR} -m 755 ${PREFIX}/lib/perl5/site_perl/${PERL_VER}
	${INSTALL_DATA} ${WRKSRC}/PV.pm ${PREFIX}/lib/perl5/site_perl/${PERL_VER}

.include <bsd.port.mk>
