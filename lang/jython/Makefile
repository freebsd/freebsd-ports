# New ports collection makefile for:	jython
# Date created:				3 April 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	jython
PORTVERSION=	2.0
CATEGORIES=	lang python java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= ${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.class
EXTRACT_ONLY=	# none

MAINTAINER=	perky@python.or.kr

BUILD_DEPENDS=	${JAVA}:${PORTSDIR}/java/linux-jdk13
RUN_DEPENDS=	${JAVA}:${PORTSDIR}/java/linux-jdk13

JAVA?=		${LOCALBASE}/linux-jdk1.3.0/bin/java
NO_BUILD=	yes

INST_PACKAGES?=	demo lib source
INST_TARGET?=	${DISTNAME}

JYTHON_PREFIX=	${LOCALBASE}/${INST_TARGET}
PLIST_SUB+=	JYTHON_DIR=${INST_TARGET}

do-install:
	cd ${DISTDIR} && ${JAVA} ${DISTNAME} -o ${JYTHON_PREFIX} ${INST_PACKAGES}
	cd ${JYTHON_PREFIX} && ./jython Lib/compileall.py Lib/

	# symbolic links for convenience
	-${LN} -s ${JYTHON_PREFIX}/jython ${LOCALBASE}/bin/jython
	-${LN} -s ${JYTHON_PREFIX}/registry ${LOCALBASE}/etc/jython.reg

.include <bsd.port.mk>
