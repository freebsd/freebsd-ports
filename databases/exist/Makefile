# Created by: Anton Yudin (<contact@toha.org.ua>)
# $FreeBSD$

PORTNAME=	exist
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	databases java
MASTER_SITES=	SF/${PORTNAME}/OldFiles
DISTNAME=	eXist-${PORTVERSION}-newcore-build4311
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Source Native XML Database

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_RC_SUBR=	eXist
REINPLACE_ARGS=	-i ''
NO_BUILD=	yes

DATADIR=	${PREFIX}/eXist
EXIST_USER?=	${WWWOWN}
EXIST_GROUP?=	${WWWGRP}

SUB_LIST=	JAVA="${JAVA}" \
		EXIST_USER=${EXIST_USER} \
		EXIST_GROUP=${EXIST_GROUP}

NO_STAGE=	yes
do-install:
	@${JAVA} -Djava.awt.headless=true -jar ${DISTDIR}/${DISTFILES} \
		-p ${DATADIR}
	@${CHOWN} -R ${EXIST_USER}:${EXIST_GROUP} ${DATADIR}

post-install:
# Fix interpreter line.
	@${FIND} ${DATADIR} -type f -name "*.sh" | ${XARGS} \
		${REINPLACE_CMD} -e 's|#!/bin/bash|#!${SH}|'

# Generate pkg-plist (at maintainer's request, after installing).
# - Configuration files and logs are saved there, so instead of producing
#   errors when removing directories, inform the user once at the end.
# - Do not generate when installing, since the configuration files would be
#   added and removed in the next update.
maint-gen-plist: install
	@if [ -f ${PLIST} ]; then \
		${ECHO_CMD} "ERROR: the packaging list already exists."; \
		${FALSE}; \
	fi
	@(cd ${DATADIR} && \
	    ${FIND} * -not -type d | ${SED} -e 's|^|%%DATADIR%%/|' && \
	    ${FIND} -d * -type d | ${SED} -e 's|^|@dirrmtry %%DATADIR%%/|' && \
	    ${ECHO_CMD} '@unexec rmdir %D/%%DATADIR%% 2>/dev/null || \
		${ECHO_CMD} "If you are permanently removing this port, remember to delete the configuration files and logs left in \"%D/%%DATADIR%%\"." | \
		${FMT}') \
	    > ${PLIST}

.include <bsd.port.mk>
