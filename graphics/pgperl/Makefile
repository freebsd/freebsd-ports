# New ports collection makefile for:	pgperl
# Version required:     1.0
# Date created:		22 December 1996
# Whom:			jmz
#
# $Id: Makefile,v 1.2 1996/12/24 07:47:28 asami Exp $
#

DISTNAME=       PGPLOT1.0b_src
PKGNAME=	pgperl-1.0
CATEGORIES=     graphics perl5
MASTER_SITES=   ftp://ftp.ast.cam.ac.uk/pgperl/perl5/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jmz@FreeBSD.org

BUILD_DEPENDS=  perl5.003:${PORTSDIR}/lang/perl5
LIB_DEPENDS=    pgplot\\.5\\.:${PORTSDIR}/graphics/pgplot
RUN_DEPENDS=    perl5.003:${PORTSDIR}/lang/perl5

WRKSRC=		${WRKDIR}/PGPLOT
ALL_TARGET=	dynamic

post-install:
	@${MKDIR} ${PREFIX}/share/doc/pgperl
	@(cd ${WRKSRC}; ${INSTALL_DATA} LICENSE pgperl.doc testpg* \
		${PREFIX}/share/doc/pgperl)

.include <bsd.port.mk>
