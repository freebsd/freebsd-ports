# New ports collection makefile for: xmolwt/gmolwt
# Date created: 1999-08-30
# Whom: Ryo MIYAMOTO <rmiya@cc.hirosaki-u.ac.jp>
#
# $FreeBSD$

PORTNAME=	xmolwt
PORTVERSION=	0.3
CATEGORIES=	biology
MASTER_SITES=	http://www.st.hirosaki-u.ac.jp/~rmiya/xmolwt/

MAINTAINER=	rmiya@cc.hirosaki-u.ac.jp

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

post-configure:
	(cd ${WRKSRC}; ${CP} Makefile.gtk Makefile)

pre-install:
	(cd ${WRKSRC}; strip gmolwt)
	${RM} -rf ${PREFIX}/share/doc/xmolwt
	${MKDIR} ${PREFIX}/share/doc/xmolwt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gmolwt ${PREFIX}/bin
	(cd ${PREFIX}/bin; ln -s gmolwt molwt)
	${INSTALL_DATA} ${WRKSRC}/Howtouse.* ${PREFIX}/share/doc/xmolwt
	${INSTALL_DATA} ${WRKSRC}/Readme ${PREFIX}/share/doc/xmolwt
	${INSTALL_DATA} ${WRKSRC}/Xmolwt ${PREFIX}/share/doc/xmolwt
	${INSTALL_DATA} ${WRKSRC}/dot.gtkrc ${PREFIX}/share/doc/xmolwt
	${INSTALL_DATA} ${WRKSRC}/*.html ${PREFIX}/share/doc/xmolwt
	${INSTALL_DATA} ${WRKSRC}/*.gif ${PREFIX}/share/doc/xmolwt

.include <bsd.port.mk>
