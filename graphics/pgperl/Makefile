# New ports collection makefile for:	pgperl
# Version required:     2.06
# Date created:		22 December 1996
# Whom:			jmz
#
# $Id: Makefile,v 1.10 1998/10/05 03:17:10 steve Exp $
#

DISTNAME=       PGPLOT-2.08
PKGNAME=	pgperl-2.08
CATEGORIES=     graphics perl5
MASTER_SITES=   ftp://ftp.ast.cam.ac.uk/pgperl/

MAINTAINER=	jmz@FreeBSD.org

LIB_DEPENDS=    pgplot.5:${PORTSDIR}/graphics/pgplot

USE_PERL5=	yes
ALL_TARGET=	dynamic

OSVERSION!=     sysctl -n kern.osreldate
.if ${OSVERSION} >= 300000
BROKEN=         depends on pgplot
.endif

MAN3=	ExtUtils::F77.3 PGPLOT.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC} && ${PERL5} Makefile.PL

post-install:
	@${MKDIR} ${PREFIX}/share/doc/pgperl
	@(cd ${WRKSRC}; ${INSTALL_DATA} LICENSE test* \
		${PREFIX}/share/doc/pgperl)

.include <bsd.port.mk>
