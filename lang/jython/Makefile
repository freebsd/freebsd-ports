# New ports collection makefile for:	jython
# Date created:				3 April 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	jython
PORTVERSION=	2.1.b2
CATEGORIES=	lang python java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= ${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.class
EXTRACT_ONLY=	# none

MAINTAINER=	perky@python.or.kr

BUILD_DEPENDS=	${JAVA}:${PORTSDIR}/java/javavmwrapper
RUN_DEPENDS=	${JAVA}:${PORTSDIR}/java/javavmwrapper

JAVA?=		${LOCALBASE}/bin/javavm
NO_BUILD=	yes

INST_PACKAGES?=	demo lib source
INST_TARGET?=	${DISTNAME:S/-//g}

JYTHON_PREFIX=	${PREFIX}/${INST_TARGET}
PLIST_SUB+=	JYTHON_DIR=${INST_TARGET}

do-install:
	cd ${DISTDIR} && ${JAVA} -classpath . ${DISTNAME} -o ${JYTHON_PREFIX} ${INST_PACKAGES}
	cd ${JYTHON_PREFIX} && ./jython Lib/compileall.py Lib/

	# symbolic links for convenience
	-${LN} -s ${JYTHON_PREFIX}/jython ${PREFIX}/bin/jython
	-${LN} -s ${JYTHON_PREFIX}/registry ${PREFIX}/etc/jython.reg

.include <bsd.port.mk>
