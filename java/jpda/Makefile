# New ports collection makefile for:   jpda
# Date created:        22 December 2000
# Whom:                Ernst de Haan <ernst@jollem.com>
#
# $FreeBSD$
#

PORTNAME=	jpda
PORTVERSION=	1.0
CATEGORIES=	java
MASTER_SITES=	http://java.sun.com/products/jpda/
DISTNAME=	jpda1_0-solsparc
EXTRACT_SUFX=	.zip

MAINTAINER=	ernst@jollem.com

RUN_DEPENDS=	${LOCALBASE}/jdk1.2.2/bin/java:${PORTSDIR}/java/jdk12-beta

NO_BUILD=	YES

USE_ZIP=	YES
JARDESTDIR=	${PREFIX}/share/java/classes/${PKGNAME}
PORTDESTDIR=	${PREFIX}/share/java/${PKGNAME}
PORTTITLE=	Java Platform Debugger Architecture
RECURSIVE_CP=	${CP} -R
WRKSRC=		${WRKDIR}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE='You must manually fetch the JPDA for Solaris distribution from http://java.sun.com/products/jpda/index.html and place it in ${DISTDIR} then run make again.'
.endif

do-install:
	@${MKDIR}                        ${JARDESTDIR}
	@${CP}    ${WRKDIR}/lib/jpda.jar ${JARDESTDIR}/
	@${MKDIR}                              ${PORTDESTDIR}
	@${CP}           ${WRKSRC}/readme.html ${PORTDESTDIR}/
	@${RECURSIVE_CP} ${WRKSRC}/doc         ${PORTDESTDIR}/
	@${RECURSIVE_CP} ${WRKSRC}/examples    ${PORTDESTDIR}/

post-install:
	@echo "${PORTTITLE} has been installed."
	@echo "Examples and docs are in ${PORTDESTDIR}/."
	@echo "The JAR file is in ${JARDESTDIR}/."
	@echo "The 'javadt' and 'jdb' scripts are not installed, they don't work (yet)."

.include <bsd.port.post.mk>
