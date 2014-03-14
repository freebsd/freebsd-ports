# Created by: Andreas Daehn <ad001@uni-rostock.de>
# $FreeBSD$

PORTNAME=	jave6
PORTVERSION=	0.1
PORTREVISION=	3
CATEGORIES=	graphics java
MASTER_SITES=	http://www.jave.de/developer/\
		http://ikaria.informatik.uni-rostock.de/public_bsd/FreeBSD/
DISTNAME=	jave_6.0_i20060105

MAINTAINER=	ad001@uni-rostock.de
COMMENT=	Java ASCII-Art-Generator

USES=		zip
USE_JAVA=	YES
JAVA_VERSION=	1.6+
NO_BUILD=	YES
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
LNKTARGET=	${PREFIX}/bin/jave6
HLPSKRIPT=	jave6

PLIST_SUB+=DATADIR=%%JAVASHAREDIR%%/${PORTNAME}

NO_STAGE=	yes
do-install:
	@${ECHO} "Installing JavE6 files in ${DATADIR}..."
	@${MKDIR} ${DATADIR}
	@${CP} -rv ${WRKDIR}/* ${DATADIR}
	@${ECHO} "creating start script ${LNKTARGET}..."
	@${ECHO} "#!/bin/sh" > ${DATADIR}/${HLPSKRIPT}
	@${ECHO} "JAVA_VERSION=${JAVA_VERSION} exec ${LOCALBASE}/bin/java -jar ${DATADIR}/jave.jar" >> ${DATADIR}/${HLPSKRIPT}
	@${CHMOD} a+x ${DATADIR}/${HLPSKRIPT}
	@${LN} -sf ${DATADIR}/${HLPSKRIPT} ${LNKTARGET}
	@${ECHO} "done."

post-install:
	@${ECHO} "Errors may occur while running the program, as it will try to access ${DATADIR}/tmp/ for output."

.include <bsd.port.mk>
