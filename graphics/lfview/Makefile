# ports collection makefile for:	lfview
# Date created:		24 February 1999
# Whom:			Yuu Yashiki
#
# $FreeBSD$
#

PORTNAME=	lfview
PORTVERSION=	1.1a 
CATEGORIES=	graphics
MASTER_SITES=	http://hoshina.denpa.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphic viewer for Leaf products

USE_IMAKE=	yes
INSTALLS_SHLIB=	yes
NO_INSTALL_MANPAGES=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lfview ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/plugins/liblfv_leaf.so.1 ${PREFIX}/lib
	${LN} -s ${PREFIX}/lib/liblfv_leaf.so.1 ${PREFIX}/lib/liblfv_leaf.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/lfview
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ja/lfview
.endif

.include <bsd.port.mk>
