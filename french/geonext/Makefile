# New ports collection makefile for:	fr-geonext
# Date created:		24 July 2003
# Whom:			Andreas Fehlner (fehlner@gmx.de)
#
# $FreeBSD$
#

PORTNAME=	geonext
PORTVERSION=	1.0
CATEGORIES=	french math
MASTER_SITES=	http://geonext.uni-bayreuth.de/content/fr/download/ \
		http://btmdx8.mat.uni-bayreuth.de/~andi/geonext/fr/
DISTNAME=	geonext_fr

MAINTAINER=	fehlner@gmx.de
COMMENT=	Interactive (dynamic) elementary Geometry Software

NO_BUILD=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}
USE_JAVA=	1.4
JAVA=		${JAVA_HOME}/bin/java
GNAME=		geonext-fr
GLOCATE=	${PREFIX}/share/${PKGNAMEPREFIX}${PORTNAME}
DATA=		cacerts didmat.crt geonext.html geonext.jar license.txt
GIF=		pixel.gif gx.gif gni.gif gn.gif g.gif x.ico

do-install:
	${MKDIR} ${GLOCATE}
	@${ECHO_MSG} '#!/bin/sh' > ${GLOCATE}/${GNAME}
	@${ECHO_MSG} '${JAVA} -cp ${GLOCATE}/geonext.jar geonext/Geonext&'\
	>>${GLOCATE}/${GNAME}
	${CHMOD} a+x ${GLOCATE}/${GNAME}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DATA} ${GLOCATE}
	cd ${WRKSRC} && ${INSTALL_DATA} ${GIF} ${GLOCATE}
	${INSTALL_SCRIPT} ${GLOCATE}/${GNAME} ${PREFIX}/bin

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
