# New ports collection makefile for:	fr-geonext
# Date created:		24 July 2003
# Whom:			Andreas Fehlner (fehlner@gmx.de)
#
# $FreeBSD$
#

PORTNAME=	geonext
PORTVERSION=	1.11
CATEGORIES=	french
MASTER_SITES=	http://geonext.uni-bayreuth.de/data/download/
DISTNAME=	geonext.${PORTVERSION}
EXTRACT_SUFX=	.zip

MAINTAINER=	fehlner@gmx.de
COMMENT=	Interactive (dynamic) elementary Geometry Software

WRKSRC=		${WRKDIR}/geonext_install
NO_BUILD=	yes
USE_ZIP=	yes
USE_JAVA=	1.4
JAVA=		${JAVA_HOME}/bin/java
GNAME=		geonext-fr
GLOCATE=	${PREFIX}/share/${GNAME}
DATA=	cacerts didmat.crt geonext.html geonext.jar license.txt index.html
IMG=	g.gif gn.gif gni.gif geoint.png pixel.gif gx.gif gxt.gif ubt.gif x.ico

do-install:
	${MKDIR} ${PREFIX}/share/${GNAME}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DATA} ${GLOCATE}
	cd ${WRKSRC} && ${INSTALL_DATA} ${IMG} ${GLOCATE}
	@${ECHO_MSG} '#!/bin/sh' > ${GLOCATE}/${GNAME}
	@${ECHO_MSG} '${JAVA} -cp ${GLOCATE}/geonext.jar geonext/Geonext language=fr&'\
	>>${GLOCATE}/${GNAME}
	${CHMOD} a+x ${GLOCATE}/${GNAME}
	${LN} ${GLOCATE}/${GNAME} ${GLOCATE}/geonext
	${INSTALL_SCRIPT} ${GLOCATE}/${GNAME} ${PREFIX}/bin
	@${ECHO_MSG} "---------------------------------------------------------"
	@${ECHO_MSG} "Application:	${GLOCATE}/geonext or ${GNAME}"
	@${ECHO_MSG} "Browser-Applet:	${GLOCATE}/geonext.html"
	@${ECHO_MSG} ""
	@${ECHO_MSG} " WWW: http://www.geonext.de"
	@${ECHO_MSG} "------------------------------------------------------"

.include <bsd.port.mk>
