# New ports collection makefile for:	jython
# Date created:				3 April 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	jython
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	lang python java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= ${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.class
EXTRACT_ONLY=	# none

MAINTAINER=	perky@FreeBSD.org
COMMENT=	An implementation of Python Interpreter in Pure Java

USE_JAVA=	1.3+
NO_BUILD=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""

INST_PACKAGES?=	demo lib source
INST_TARGET?=	${DISTNAME:S/-//g}
JYTHON_PREFIX=	${PREFIX}/${INST_TARGET}
PLIST_SUB+=	JYTHON_DIR=${INST_TARGET}

CACHEDIR_SPEC=	-Dpython.cachedir=${WRKDIR}/jython-cachedir

do-install:
	@# Do tons of backflips so that the cachedir is put into the user's home
	@# directory (it's irritating to not be able to cache stuff if you're
	@# not root).  Furthermore, don't leave a cachedir around from either a
	@# port install or a package install, but do cache the *.py files in Lib
	@# during a port install or a package install.
	cd ${DISTDIR} && ${JAVA} ${CACHEDIR_SPEC} -classpath . ${DISTNAME} \
	    -o ${JYTHON_PREFIX} ${INST_PACKAGES}
	${REINPLACE_CMD} \
		's/-cl/"-Dpython.cachedir=$${HOME}\/.jython-cachedir" -cl/g' \
		${JYTHON_PREFIX}/jython
	${REINPLACE_CMD} 's/^python\.cachedir/#&/g' ${JYTHON_PREFIX}/registry
	${JYTHON_PREFIX}/jython ${CACHEDIR_SPEC} -c None

	@# Install symbolic links for convenience.
	-${LN} -sf ${JYTHON_PREFIX}/jython ${PREFIX}/bin/jython
	-${LN} -sf ${JYTHON_PREFIX}/jythonc ${PREFIX}/bin/jythonc
	-${LN} -sf ${JYTHON_PREFIX}/registry ${PREFIX}/etc/jython.reg

.include <bsd.port.mk>
