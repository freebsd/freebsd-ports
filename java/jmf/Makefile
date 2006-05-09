# New ports collection makefile for:    Java Media Framework
# Date created:				Sat Oct 25 16:05:29 EEST 2003
# Whom:					Anton Yudin <toha@toha.org.ua>
#
# $FreeBSD$
#

PORTNAME=	jmf
PORTVERSION=	2.1.1e
CATEGORIES=	java
MASTER_SITES=	#http://java.sun.com/products/java-media/jmf/2.1.1/download.html
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}-alljava
DISTFILES=	${DISTNAME}.zip

MAINTAINER=	toha@toha.org.ua
COMMENT=	Java Media Framework

USE_JAVA=	yes
JAVA_VERSION=	1.2+
USE_ZIP=	YES
NO_BUILD=	YES

WRKSRC=		${WRKDIR}/JMF-${PORTVERSION}

RESTRICTED=	"Redistribution of pre-compiled binaries is not permitted"
NO_CDROM=	"Redistribution of pre-compiled binaries is not permitted"
NO_PACKAGE=	"Redistribution of pre-compiled binaries is not permitted"

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

# Check for JMF sources
.if !exists(${DISTDIR}/${DISTFILES}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=/usr/bin/printf
IGNORE=	:\n\
Because of licensing restrictions, you must fetch the source distribution\n\
manually.  Please access:\n\
http://java.sun.com/products/java-media/jmf/2.1.1/download.html\n\
with a web browser and follow the \"Download JMF ${PORTVERSION}\" link\n\
Select download format: cross-platform format\n\
Please place this file in ${DISTDIR}.\n
.endif

do-configure:
	${RM} ${WRKSRC}/bin/*.orig
	for file in `${LS} ${WRKSRC}/bin/jm*`; do \
		${REINPLACE_CMD} -e "s:%%JAVAJARDIR%%:${JAVAJARDIR}:g" -e "s:%%PREFIX%%:${PREFIX}:g" $${file}; \
	done
	${RM} ${WRKSRC}/bin/*.bak

do-install:
	-${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/jm* ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${WRKSRC}/lib/jmf.properties \
		${JAVAJARDIR}/
.if !defined(NOPORTDOCS)
	-${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
