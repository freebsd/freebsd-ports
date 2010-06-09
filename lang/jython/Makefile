# New ports collection makefile for:	jython
# Date created:				3 April 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	jython
PORTVERSION=	2.5.1
CATEGORIES=	lang python java
MASTER_SITES=	SF
DISTNAME=	jython_installer-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=	# none

MAINTAINER=	python@FreeBSD.org
COMMENT=	An implementation of Python Interpreter in Pure Java

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes
REINPLACE_ARGS=	-i ""

INST_TARGET?=	lib/jython
JYTHON_PREFIX=	${PREFIX}/${INST_TARGET}
PLIST_SUB+=	JYTHON_DIR=${INST_TARGET}

CACHEDIR_SPEC=	-Dpython.cachedir=${WRKDIR}/jython-cachedir

do-install:
	@# Do tons of backflips so that the cachedir is put into the user's home
	@# directory (it's irritating to not be able to cache stuff if you're
	@# not root).  Furthermore, don't leave a cachedir around from either a
	@# port install or a package install, but do cache the *.py files in Lib
	@# during a port install or a package install.
	cd ${DISTDIR} && ${JAVA} ${CACHEDIR_SPEC} \
		-jar ${DISTNAME}${EXTRACT_SUFX} \
		--silent -d ${JYTHON_PREFIX} -t standard
	${REINPLACE_CMD} \
		's/-cl/"-Dpython.cachedir=$${HOME}\/.jython-cachedir" -cl/g' \
		${JYTHON_PREFIX}/jython
	${REINPLACE_CMD} 's/^python\.cachedir/#&/g' ${JYTHON_PREFIX}/registry
	${JYTHON_PREFIX}/jython ${CACHEDIR_SPEC} -c None

	@# Install symbolic links for convenience.
	-${LN} -sf ${JYTHON_PREFIX}/jython ${PREFIX}/bin/jython
	-${LN} -sf ${JYTHON_PREFIX}/registry ${PREFIX}/etc/jython.reg

.include <bsd.port.mk>
