# New ports collection makefile for:	p5-Penguin-Easy
# Version required:			1.1
# Date created:				May 28th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	Penguin-Easy-1.1
PKGNAME=	p5-Penguin-Easy-1.1
CATEGORIES=	devel security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Penguin

MAINTAINER=	jfitz@FreeBSD.org

BUILD_DEPENDS= 	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Penguin.pm:${PORTSDIR}/devel/p5-Penguin

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Penguin::Easy.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

post-install:
		${MKDIR} ${PREFIX}/lib/perl5/site_perl/Penguin/Easy/bin ${PREFIX}/lib/perl5/site_perl/Penguin/Easy/doc
		${INSTALL} -c -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ${WRKSRC}/bin/ep ${PREFIX}/lib/perl5/site_perl/Penguin/Easy/bin
		${INSTALL_DATA} ${WRKSRC}/Penguin-howto ${PREFIX}/lib/perl5/site_perl/Penguin/Easy/doc

.include <bsd.port.mk>
