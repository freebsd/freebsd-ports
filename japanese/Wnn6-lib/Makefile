# New ports collection makefile for:	head files and libraries of Wnn6
# Version required:	97.6.6
# Date created:		11 July 1997
# Whom:			Satoshi Taoka <taoka@infonets.hiroshima-u.ac.jp>
#
# $Id: Makefile,v 1.17 1997/09/10 06:51:52 asami Exp $
#

DISTNAME=	FreeBSD-2.2R
PKGNAME=	jp-Wnn6-lib-97.6.6
CATEGORIES=	japanese
MASTER_SITES=	file://localhost${PREFIX}/OMRONWnn6/wnnsdk/sdk/ \
		ftp://ftp.omronsoft.co.jp/pub/Wnn6/sdk/

MAINTAINER=	taoka@infonets.hiroshima-u.ac.jp

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	Wnn6-lib
DOCDIR=		${PREFIX}/share/doc/Wnn6-lib

NO_BUILD=	yes
NO_CONFIGURE=	yes
NO_PATCH=	yes

do-install:
	@${MKDIR} ${PREFIX}/include/wnn
	@${INSTALL_DATA} ${WRKSRC}/include/wnn/* ${PREFIX}/include/wnn
	@${INSTALL_DATA} ${WRKSRC}/lib/libwnn.a ${PREFIX}/lib
	@${MKDIR} ${DOCDIR}
	@${INSTALL_DATA} ${FILESDIR}/copyright.jp ${DOCDIR}

.include <bsd.port.mk>
