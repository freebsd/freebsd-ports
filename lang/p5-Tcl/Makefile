# New ports collection makefile for:	p5-Tcl
# Version required:			b2
# Date created:				June 15th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.4 1997/11/22 01:11:25 asami Exp $
#

DISTNAME=	Tcl-b2
PKGNAME=	p5-Tcl-b2
CATEGORIES=	lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tcl

MAINTAINER=	jfitz@FreeBSD.ORG

LIB_DEPENDS=	tcl76\\.1:${PORTSDIR}/lang/tcl76

USE_PERL5=	YES

WRKSRC=		${WRKDIR}/Tcl

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Tcl.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
