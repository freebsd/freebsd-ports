# New ports collection makefile for:	p5-Penguin
# Version required:			3.00
# Date created:				May 28th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	Penguin-3.00
PKGNAME=	p5-Penguin-3.00
CATEGORIES=	devel security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Penguin

MAINTAINER=	jfitz@FreeBSD.org

RUN_DEPENDS=	pgp:${PORTSDIR}/security/pgp

USE_PERL5=	YES

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

post-install:
		${MKDIR} ${PREFIX}/lib/perl5/site_perl/Penguin/bin ${PREFIX}/lib/perl5/site_perl/Penguin/misc ${PREFIX}/lib/perl5/site_perl/Penguin/doc
		${INSTALL_DATA} ${WRKSRC}/bin/.pen ${PREFIX}/lib/perl5/site_perl/Penguin/bin
.for file in makeapplet pclient penguind runapplet
		${INSTALL} -c -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ${WRKSRC}/bin/${file} ${PREFIX}/lib/perl5/site_perl/Penguin/bin
.endfor
		${INSTALL_DATA} ${WRKSRC}/misc/* ${PREFIX}/lib/perl5/site_perl/Penguin/misc
.for file in FAQ INSTALL MODULE_NOTES README SECURITY TODO
		${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/perl5/site_perl/Penguin/doc
.endfor

.include <bsd.port.mk>
