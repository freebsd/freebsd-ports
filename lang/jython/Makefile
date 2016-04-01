# Created by: Hye-Shik Chang <perky@python.or.kr>
# $FreeBSD$

PORTNAME=	jython
PORTVERSION=	2.7.0
CATEGORIES=	lang python java
MASTER_SITES=	https://repo1.maven.org/maven2/org/python/jython-installer/${PORTVERSION}/ \
		http://repo1.maven.org/maven2/org/python/jython-installer/${PORTVERSION}/
DISTNAME=	jython-installer-${PORTVERSION}
EXTRACT_SUFX=	.jar

MAINTAINER=	python@FreeBSD.org
COMMENT=	Implementation of Python Interpreter in Pure Java

LICENSE=	PSFL APACHE20
LICENSE_COMB=	multi
LICENSE_FILE_PSFL=	${WRKDIR}/LICENSE.txt
LICENSE_FILE_APACHE20=	${WRKDIR}/LICENSE_Apache.txt

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

# Extract only license files
EXTRACT_AFTER_ARGS=	--no-same-owner --no-same-permissions \
			LICENSE.txt LICENSE_Apache.txt
USE_JAVA=	yes
JAVA_VERSION=	1.7+
NO_BUILD=	yes
NO_ARCH=	yes
REINPLACE_ARGS=	-i ""

INST_TARGET?=	lib/jython
JYTHON_PREFIX=	${PREFIX}/${INST_TARGET}
PLIST_SUB+=	JYTHON_DIR=${INST_TARGET}

# Do tons of backflips so that the cachedir is put into the user's home
# directory (it's irritating to not be able to cache stuff if you're
# not root).  Furthermore, don't leave a cachedir around from either a
# port install or a package install, but do cache the *.py files in Lib
# during a port install or a package install.
do-install:
# Null the PATH so installer won't find the python2.7 executable
# and won't build a python launcher instead of bash one
	cd ${DISTDIR} && PATH="" ${JAVA} \
		-jar ${DISTNAME}${EXTRACT_SUFX} \
		--silent -d ${STAGEDIR}${JYTHON_PREFIX} -t standard -e ensurepip
# Place python.cachedir in user's home directory by default
	${REINPLACE_CMD} \
		's|\"$$JAVA_OPTS|\"-Dpython.cachedir=$${HOME}/.jython-cachedir $$JAVA_OPTS|g' \
		${STAGEDIR}${JYTHON_PREFIX}/bin/jython
# Teach bin/jython script to solve symlinks the right way
	${REINPLACE_CMD} \
		's,if expr "$$link" : '\''/'\'' > /dev/null; then,if expr "$$link" : '\''^/'\'' > /dev/null; then,' \
		${STAGEDIR}${JYTHON_PREFIX}/bin/jython
# Delete python.cachedir entry from Jython's registry file
	${REINPLACE_CMD} 's/^python\.cachedir/#&/g' \
		${STAGEDIR}${JYTHON_PREFIX}/registry
# Compile all the *.py files to *$py.class files, override HOME and user.home to place
# .jython-cachedir and .jline-jython.history in WRKDIR
	-HOME=${WRKDIR} JAVA_OPTS="-Duser.home=${WRKDIR}" \
		${STAGEDIR}${JYTHON_PREFIX}/bin/jython \
		-m compileall -d ${JYTHON_PREFIX} ${STAGEDIR}${JYTHON_PREFIX}

# Install symbolic links for convenience.
	${LN} -sf ${JYTHON_PREFIX}/bin/jython ${STAGEDIR}${PREFIX}/bin/jython
	${LN} -sf ${JYTHON_PREFIX}/registry ${STAGEDIR}${PREFIX}/etc/jython.reg

.include <bsd.port.mk>
