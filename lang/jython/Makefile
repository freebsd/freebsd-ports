# Created by: Hye-Shik Chang <perky@python.or.kr>
# $FreeBSD$

PORTNAME=	jython
PORTVERSION=	2.5.3
CATEGORIES=	lang python java
MASTER_SITES=	http://central.maven.org/maven2/org/python/jython-installer/${PORTVERSION}/
DISTNAME=	jython-installer-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=	# none

MAINTAINER=	python@FreeBSD.org
COMMENT=	An implementation of Python Interpreter in Pure Java

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
REINPLACE_ARGS=	-i ""

INST_TARGET?=	lib/jython
JYTHON_PREFIX=	${PREFIX}/${INST_TARGET}
PLIST_SUB+=	JYTHON_DIR=${INST_TARGET}

CACHEDIR_SPEC=	-Dpython.cachedir=${WRKDIR}/jython-cachedir

# Do tons of backflips so that the cachedir is put into the user's home
# directory (it's irritating to not be able to cache stuff if you're
# not root).  Furthermore, don't leave a cachedir around from either a
# port install or a package install, but do cache the *.py files in Lib
# during a port install or a package install.
do-install:
	cd ${DISTDIR} && ${JAVA} ${CACHEDIR_SPEC} \
		-jar ${DISTNAME}${EXTRACT_SUFX} \
		--silent -d ${STAGEDIR}${JYTHON_PREFIX} -t standard
	${REINPLACE_CMD} \
		's|-cl|"-Dpython.cachedir=$${HOME}/.jython-cachedir" -cl|g ; \
		s|${STAGEDIR}||' \
		${STAGEDIR}${JYTHON_PREFIX}/jython
	${REINPLACE_CMD} \
		's,if expr "$$link" : '\''/'\'' > /dev/null; then,if expr "$$link" : '\''^/'\'' > /dev/null; then,' \
		${STAGEDIR}${JYTHON_PREFIX}/jython
	${REINPLACE_CMD} 's/^python\.cachedir/#&/g' \
		${STAGEDIR}${JYTHON_PREFIX}/registry
	${STAGEDIR}${JYTHON_PREFIX}/jython ${CACHEDIR_SPEC} -c None

# Install symbolic links for convenience.
	-${LN} -sf ${JYTHON_PREFIX}/jython ${STAGEDIR}${PREFIX}/bin/jython
	-${LN} -sf ${JYTHON_PREFIX}/registry ${STAGEDIR}${PREFIX}/etc/jython.reg

.include <bsd.port.mk>
