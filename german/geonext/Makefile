# New ports collection makefile for:	de-geonext
# Date created:		24 July 2003
# Whom:			Andreas Fehlner (fehlner@gmx.de)
#
# $FreeBSD$
#

PORTNAME=	geonext
PORTVERSION=	1.0
CATEGORIES=	german
MASTER_SITES=	http://geonext.uni-bayreuth.de/data/download/linux/
PKGNAMEPREFIX?=	de-
DISTNAME=	geonext
EXTRACT_SUFX=	.tgz

MAINTAINER=	fehlner@gmx.de
COMMENT=	Interactive (dynamic) elementary Geometry Software

WRKSRC=		${WRKDIR}/geonext_install
NO_BUILD=	yes
#USE_JAVA=	1.4
#JAVA=		${JAVA_HOME}/bin/java
GNAME=		geonext-de
GLOCATE=	${PREFIX}/share/${GNAME}
DATA=	cacerts didmat.crt geonext.html geonext.jar license.txt index.html
GIF=	pixel.gif gx.gif gni.gif gn.gif g.gif x.ico

do-install:
	${MKDIR} ${PREFIX}/share/${GNAME}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DATA} ${GLOCATE}
	cd ${WRKSRC} && ${INSTALL_DATA} ${GIF} ${GLOCATE}
	@${ECHO_MSG} '#!/bin/sh' > ${GLOCATE}/${GNAME}
	@${ECHO_MSG} '${JAVA} -cp ${GLOCATE}/geonext.jar geonext/Geonext&'\
	>>${GLOCATE}/${GNAME}
	${CHMOD} a+x ${GLOCATE}/${GNAME}
	${SED} -e 's/GEONExT.html/geonext.html/' ${GLOCATE}/index.html > \
	${GLOCATE}/index.tmp
	${LN} ${GLOCATE}/${GNAME} ${GLOCATE}/geonext
	${MV} ${GLOCATE}/index.tmp ${GLOCATE}/index.html
	${INSTALL_SCRIPT} ${GLOCATE}/geonext-de ${PREFIX}/bin
	@${ECHO_MSG} "---------------------------------------------------------"
	@${ECHO_MSG} "Application:	${GLOCATE}/geonext or geonext-de"
	@${ECHO_MSG} "Browser-Applet:	${GLOCATE}/geonext.html"
	@${ECHO_MSG} ""
	@${ECHO_MSG} " WWW: http://www.geonext.de"
	@${ECHO_MSG} "------------------------------------------------------"

.include <bsd.port.mk>
