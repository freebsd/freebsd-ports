# New ports collection makefile for:	pgperl
# Version required:     2.06
# Date created:		22 December 1996
# Whom:			jmz
#
# $Id: Makefile,v 1.6 1997/08/15 15:02:07 jmz Exp $
#

DISTNAME=       PGPLOT-2.08
PKGNAME=	pgperl-2.08
CATEGORIES=     graphics perl5
MASTER_SITES=   ftp://ftp.ast.cam.ac.uk/pgperl/

MAINTAINER=	jmz@FreeBSD.org

LIB_DEPENDS=    pgplot\\.5\\.:${PORTSDIR}/graphics/pgplot

USE_PERL5=	yes
ALL_TARGET=	dynamic

do-configure:
	@cd ${WRKSRC} && ${PREFIX}/bin/perl Makefile.PL

post-install:
	@${MKDIR} ${PREFIX}/share/doc/pgperl
	@(cd ${WRKSRC}; ${INSTALL_DATA} LICENSE test* \
		${PREFIX}/share/doc/pgperl)

.include <bsd.port.mk>
