# New ports collection makefile for:	cccc
# Version required:			2.1.1
# Date created:				12 September 1997
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.2 1998/08/13 03:30:27 asami Exp $
#

DISTNAME=		cccc-2.1.1.src
PKGNAME=		cccc-2.1.1
CATEGORIES=		devel textproc www
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	devel/lang/c++

MAINTAINER=		andy@icc.surw.chel.su

BUILD_DEPENDS=		antlr:${PORTSDIR}/devel/pccts \
			dlg:${PORTSDIR}/devel/pccts

WRKSRC=			${WRKDIR}/usr/local/src/cccc-2.1.1
USE_GMAKE=		yes
MAKEFILE=		makefile
MAKE_ENV=		OSTYPE=FreeBSD

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/cccc ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/cccc
.for file in cccc_inf.dat cccc_met.dat cccc_tmt.dat cccc_ug.htm
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/cccc
.endfor
	@ ${MKDIR} ${PREFIX}/share/doc/cccc
	@ ${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/cccc

.include <bsd.port.mk>
