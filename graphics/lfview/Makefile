# ports collection makefile for:	lfview
# Version required:	1.1beta2
# Date created:		24 February 1999
# Whom:			Yuu Yashiki
#
# $FreeBSD$
#

DISTNAME=	lfview11beta2
PKGNAME=	lfview-1.1b2
CATEGORIES=	graphics
MASTER_SITES=	http://www.geocities.co.jp/Playtown/6344/
EXTRACT_SUFX=	.tgz

MAINTAINER=	s974123@cc.matsuyama-u.ac.jp

WRKSRC=		${WRKDIR}/lfview1.1beta2
USE_IMAKE=	yes

NO_INSTALL_MANPAGES=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lfview ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/plugins/liblfv_leaf.so.1 ${PREFIX}/lib
	${LN} -s ${WRKSRC}/plugins/liblfv_leaf.so ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/lfview
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ja/lfview
.endif

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
