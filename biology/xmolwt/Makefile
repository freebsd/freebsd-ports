# New ports collection makefile for:	xmolwt/gmolwt
# Date created:		1999-08-30
# Whom:			Ryo MIYAMOTO <rmiya@cc.hirosaki-u.ac.jp>
#
# $FreeBSD$

PORTNAME=	xmolwt
PORTVERSION=	0.7
CATEGORIES=	biology
MASTER_SITES=	http://www.st.hirosaki-u.ac.jp/~rmiya/xmolwt/

MAINTAINER=	rmiya@cc.hirosaki-u.ac.jp

WRKSRC=		${WRKDIR}/${DISTNAME}
MAKEFILE=	Makefile.gtk

USE_GMAKE=	yes
USE_GTK=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gmolwt ${PREFIX}/bin
	${LN} -sf gmolwt ${PREFIX}/bin/molwt
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xmolwt
	${INSTALL_DATA} ${WRKSRC}/Howtouse.* ${PREFIX}/share/doc/xmolwt
	${INSTALL_DATA} ${WRKSRC}/Readme ${PREFIX}/share/doc/xmolwt
	${INSTALL_DATA} ${WRKSRC}/Xmolwt ${PREFIX}/share/doc/xmolwt
	${INSTALL_DATA} ${WRKSRC}/dot.gtkrc ${PREFIX}/share/doc/xmolwt
	${INSTALL_DATA} ${WRKSRC}/*.html ${PREFIX}/share/doc/xmolwt
	${INSTALL_DATA} ${WRKSRC}/*.gif ${PREFIX}/share/doc/xmolwt
.endif

.include <bsd.port.mk>
