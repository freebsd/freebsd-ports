# New ports collection makefile for:    Java Servlet Developpers Kit
# Version required:	2.0
# Date created:		1999/05/29
# Whom:			Kensaku Masuda <greg@greg.rim.or.jp>
#
# $Id: Makefile,v 1.1.1.1 1999/06/23 15:05:39 kuriyama Exp $
#

DISTNAME=	jsdk20-solaris2-sparc
PKGNAME=	jsdk-2.0
CATEGORIES=	java
MASTER_SITES=	
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	greg@greg.rim.or.jp

RUN_DEPENDS=	${PREFIX}/jdk1.1.8/bin/java:${PORTSDIR}/lang/jdk

NO_CDROM=	"Sun has a funky license for this software"
RESTRICTED=	"no commercial use"

WRKSRC=		${WRKDIR}/JSDK2.0
NO_BUILD=	yes

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
	  @{ECHO} "=========================================================="; \
	  @{ECHO} "You must retriving a archive from"; \
	  @{ECHO} "	http://java.sun.com/products/servlet/index.html"; \
	  @{ECHO} "And copy into ${DISTDIR}"; \
	  @{ECHO} "=========================================================="; \
	 fi

do-install:
	${MKDIR} ${PREFIX}/JSDK2.0
	(cd ${WRKSRC} && tar -c -f - .) \
		| (cd ${PREFIX}/JSDK2.0 && tar fx -)

.include <bsd.port.mk>
