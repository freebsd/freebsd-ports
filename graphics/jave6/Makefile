# Ports collection makefile for:	Jave
# Date created:				29 January 2006
# Whom:					Andreas Daehn <ad001@uni-rostock.de>
#
# $FreeBSD$

PORTNAME=	jave6
PORTVERSION=	0.1
CATEGORIES=	graphics java
MASTER_SITES=	http://www.jave.de/developer/\
		http://ikaria.inf.fsr.uni-rostock.de/freebsd_public/
DISTNAME=	jave_6.0_i20060105
EXTRACT_SUFX=	.zip

MAINTAINER=	ad001@uni-rostock.de
COMMENT=	Java ASCII-Art-Generator

USE_JAVA=	YES
USE_ZIP=	YES
JAVA_VERSION=	1.3+
NO_BUILD=	YES
JARTARGETDIR=	${TARGETDIR}/jave6
LNKTARGET=	${TARGETDIR}/bin/jave6
HLPSKRIPT=	jave6

do-install:
	@${ECHO} "Installing JavE6 files in ${JARTARGETDIR}..."
	@${MKDIR} ${JARTARGETDIR}
	@${CP} -rv ${WRKDIR}/* ${JARTARGETDIR}
	@${ECHO} "creating start script ${LNKTARGET}..."
	@${ECHO} "#!/bin/sh" > ${JARTARGETDIR}/${HLPSKRIPT}
	@${ECHO} ${JAVA_HOME}/bin/java -jar ${JARTARGETDIR}/jave.jar >> ${JARTARGETDIR}/${HLPSKRIPT}
	@${CHMOD} a+x ${JARTARGETDIR}/${HLPSKRIPT}
	@${LN} -sf ${JARTARGETDIR}/${HLPSKRIPT} ${LNKTARGET}
	@${ECHO} "done."

post-install:
	@${ECHO} "Errors may occur while running the program, as it will try to access ${JARTARGETDIR}/tmp/ for output."

.include <bsd.port.mk>
