# New ports collection makefile for:	p5-Tcl
# Version required:			b2
# Date created:				June 15th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	Tcl-b2
PKGNAME=	p5-Tcl-b2
CATEGORIES=	lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tcl

MAINTAINER=	jfitz@FreeBSD.org

LIB_DEPENDS=	tcl82.1:${PORTSDIR}/lang/tcl82

USE_PERL5=	YES

WRKSRC=		${WRKDIR}/Tcl

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Tcl.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
