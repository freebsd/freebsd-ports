# New ports collection makefile for:    Java Servlet Developpers Kit
# Date created:		1999/05/29
# Whom:			Kensaku Masuda <greg@greg.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	jsdk
PORTVERSION=	2.0
CATEGORIES=	java
MASTER_SITES=	
DISTNAME=	jsdk20-solaris2-sparc
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	greg@greg.rim.or.jp

USE_JAVA=	1.1+

NO_CDROM=	"Sun has a funky license for this software"
RESTRICTED=	"no commercial use"

WRKSRC=		${WRKDIR}/JSDK2.0

.if defined(BATCH) || defined(PACKAGE_BUILDING)
IGNORE=		"Should be fetched manually"
.endif

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${ECHO} "=========================================================="; \
		${ECHO} " You must a fetch the Java Servlet Development Kit 2.0"; \
		${ECHO} " (for Unix) archive from"; \
		${ECHO} ""; \
		${ECHO} "     http://java.sun.com/products/servlet/download.html"; \
		${ECHO} ""; \
		${ECHO} " And copy into ${DISTDIR}"; \
		${ECHO} "=========================================================="; \
	 fi

do-build:
	@${SED} -e s,%%PREFIX%%,${PREFIX},g \
		${WRKSRC}/bin/servletrunner > ${WRKDIR}/servletrunner

do-install:
	@${MKDIR} ${PREFIX}/share/java/classes ${PREFIX}/share/java/jsdk20
	@${INSTALL_SCRIPT} ${WRKDIR}/servletrunner ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/lib/jsdk.jar ${PREFIX}/share/java/classes
	@cd ${WRKSRC}; \
	 ${CP} -R [Rde]* ${PREFIX}/share/java/jsdk20

.include <bsd.port.mk>
