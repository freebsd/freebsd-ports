# ports collection makefile for:	lfview
# Date created:		24 February 1999
# Whom:			Yuu Yashiki
#
# $FreeBSD$
#

PORTNAME=	lfview
PORTVERSION=	1.1.b3
CATEGORIES=	graphics
MASTER_SITES=	http://www.geocities.co.jp/Playtown/6344/
DISTNAME=	lfview11beta3
EXTRACT_SUFX=	.tgz

MAINTAINER=	s974123@cc.matsuyama-u.ac.jp

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lfview ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/plugins/liblfv_leaf.so.1 ${PREFIX}/lib
	${LN} -s ${PREFIX}/lib/liblfv_leaf.so.1 ${PREFIX}/lib/liblfv_leaf.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/lfview
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ja/lfview
.endif

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
