# New ports collection makefile for:	Java Foundation Classes with Swing
# Version required:	1.1
# Date created:		17 May 1999
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.ORG>
#
# $FreeBSD$
#

DISTNAME=	swing11
PKGNAME=	jfc-1.1
CATEGORIES=	java
MASTER_SITES=	http://java.sun.com/products/jfc/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	kuriyama@FreeBSD.ORG

RUN_DEPENDS=	${PREFIX}/${JAVASUBDIR}/bin/java:${PORTSDIR}/java/jdk

RESTRICTED=	"Cannot distribute without value-added application."
WRKSRC=		${WRKDIR}/swing-1.1
NO_BUILD=	YES
PLIST_SUB=	JFCSUBDIR=${JFCSUBDIR}

JAVASUBDIR=	jdk1.1.8
JFCSUBDIR=	swing-1.1

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTFILES} ]; then \
		${ECHO} "Please fetch \"${DISTFILES}\" and put it in"; \
		${ECHO} "\"${DISTDIR}\" manually."; \
		exit 1; \
	 fi

do-install:
	${MKDIR} ${PREFIX}/${JFCSUBDIR}
	(cd ${WRKSRC} && tar -c -f - .) \
		| (cd ${PREFIX}/${JFCSUBDIR} && tar fx -)
	${CHOWN} -R ${SHAREOWN}.${SHAREGRP} ${PREFIX}/${JFCSUBDIR}

.include <bsd.port.mk>
