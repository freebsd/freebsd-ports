# ports collection makefile for:   xosmulti
# Version required:    1.00
# Date created:        17 February 1999
# Whom:                Seiichirou Hiraoka
#
# $Id$
#

DISTNAME=	xosmulti_1.00_tar
PKGNAME=	xosmulti-1.00
CATEGORIES=	games
MASTER_SITES=	http://www01.u-page.so-net.ne.jp/ka2/nakanita/multi/
EXTRACT_SUFX=	.gz

MAINTAINER=	flathill@FreeBSD.ORG

WRKSRC=		${WRKDIR}/xosmulti
USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xosmulti ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/xosmulti
	${INSTALL_MAN} ${WRKSRC}/README.jp ${PREFIX}/share/doc/ja/xosmulti
.endif

.include <bsd.port.mk>
