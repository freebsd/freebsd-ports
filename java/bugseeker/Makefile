# New ports collection makefile for:   bugseeker
# Date created:        22 December 2000
# Whom:                Ernst de Haan <ernst@jollem.com>
#
# $FreeBSD$
#

PORTNAME=	bugseeker
PORTVERSION=	1.0.2
CATEGORIES=	java
MASTER_SITES=	http://www.karmira.com/products/bugseeker2/download/
DISTNAME=	bugseeker2ee-1_0_2

PATCH_SITES=	http://www.jollem.com/~ernst/
PATCHFILES=	bugseeker2.sh.diff

MAINTAINER=	ernst@jollem.com

RUN_DEPENDS=	${LOCALBASE}/linux-jdk1.3.0/bin/java:${PORTSDIR}/java/linux-jdk13

NO_BUILD=	YES

WRKSRC=		${WRKDIR}/bugseeker2
PORTDESTDIR=	${PREFIX}/${PORTNAME}${PORTVERSION}
PORTTITLE=	BugSeeker for Java 2 (Enterprise Edition)
RECURSIVE_CP=	${CP} -R

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE='You must manually obtain the ${DISTNAME}${EXTRACT_SUFX} file from Karmira, at http://www.karmira.com/store/index.html'
.endif

do-install:
	@${MKDIR}                              ${PORTDESTDIR}
	@${CP}           ${WRKSRC}/changes.txt ${PORTDESTDIR}/
	@${CP}           ${WRKSRC}/license.txt ${PORTDESTDIR}/
	@${CP}           ${WRKSRC}/readme.txt  ${PORTDESTDIR}/
	@${MKDIR}                              ${PORTDESTDIR}/bin
	@${CP}           ${WRKSRC}/bin/bugseeker2.sh ${PORTDESTDIR}/bin/bugseeker.sh
	@${MKDIR}                              ${PORTDESTDIR}/lib
	@${RECURSIVE_CP} ${WRKSRC}/lib/*       ${PORTDESTDIR}/lib/
	@${MKDIR}                              ${PORTDESTDIR}/manual
	@${RECURSIVE_CP} ${WRKSRC}/manual/*    ${PORTDESTDIR}/manual/

post-install:
	@echo "${PORTTITLE} has been installed in ${PORTDESTDIR}."

.include <bsd.port.post.mk>
