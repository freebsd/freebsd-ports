# New ports collection makefile for:	p5-PerlMenu
# Date created:				August 14, 2000
# Whom:	      				John Baldwin <jhb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PerlMenu
PORTVERSION=	4.0
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/S/SK/SKUNZ
PKGNAMEPREFIX=	p5-
DISTNAME=	perlmenu.v4.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 module for displaying menus with Curses

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Curses.pm:${PORTSDIR}/devel/p5-Curses

USE_PERL5=	yes
NO_BUILD=	yes
PLIST_FILES=	%%SITE_PERL%%/perlmenu.pm

do-install:
	${INSTALL_DATA} ${WRKSRC}/perlmenu.pm ${SITE_PERL}

.include <bsd.port.mk>
