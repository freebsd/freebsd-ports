# New ports collection makefile for:    Java Servlet Developpers Kit
# Version required:	2.0
# Date created:		1999/05/29
# Whom:			Kensaku Masuda <greg@greg.rim.or.jp>
#
# $FreeBSD$
#

DISTNAME=	jsdk20-solaris2-sparc
PKGNAME=	jsdk-2.0
CATEGORIES=	java
MASTER_SITES=	
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	greg@greg.rim.or.jp

RUN_DEPENDS=	${PREFIX}/jdk1.1.8/bin/java:${PORTSDIR}/java/jdk

NO_CDROM=	"Sun has a funky license for this software"
RESTRICTED=	"no commercial use"

WRKSRC=		${WRKDIR}/JSDK2.0

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
	  ${ECHO_MSG} "=========================================================="; \
	  ${ECHO_MSG} "You must retriving a archive from"; \
	  ${ECHO_MSG} "	http://java.sun.com/products/servlet/index.html"; \
	  ${ECHO_MSG} "And copy into ${DISTDIR}"; \
	  ${ECHO_MSG} "=========================================================="; \
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
