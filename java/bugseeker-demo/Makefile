# New ports collection makefile for:   bugseeker
# Date created:        22 December 2000
# Whom:                Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bugseeker-demo
PORTVERSION=	1.0.2
CATEGORIES=	java
MASTER_SITES=	http://www.karmira.com/products/bugseeker2/download/
DISTNAME=	bugseeker2demo

PATCH_SITES=	http://www.metaverse.nl/~ernst/
PATCHFILES=	bugseeker2demo.sh.diff

MAINTAINER=	znerd@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/linux-sun-jdk1.3.1/bin/java:${PORTSDIR}/java/linux-sun-jdk13

NO_BUILD=	YES

WRKSRC=		${WRKDIR}/${DISTNAME}
PORTDESTDIR=	${PREFIX}/${PORTNAME}${PORTVERSION}
PORTTITLE=	BugSeeker for Java 2 (Trial version)
RECURSIVE_CP=	${CP} -R

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR}                              ${PORTDESTDIR}
	@${CP}           ${WRKSRC}/changes.txt ${PORTDESTDIR}/
	@${CP}           ${WRKSRC}/license.txt ${PORTDESTDIR}/
	@${CP}           ${WRKSRC}/readme.txt  ${PORTDESTDIR}/
	@${MKDIR}                              ${PORTDESTDIR}/bin
	@${CP}           ${WRKSRC}/bin/bugseeker2demo.sh ${PORTDESTDIR}/bin/bugseeker.sh
	@${MKDIR}                              ${PORTDESTDIR}/lib
	@${RECURSIVE_CP} ${WRKSRC}/lib/*       ${PORTDESTDIR}/lib/
	@${MKDIR}                              ${PORTDESTDIR}/manual
	@${RECURSIVE_CP} ${WRKSRC}/manual/*    ${PORTDESTDIR}/manual/

post-install:
	@echo "${PORTTITLE} has been installed in ${PORTDESTDIR}."
	@echo "If you don't have a trial license yet, then you can get a 30-day license at:"
	@echo "http://www.karmira.com/products/bugseeker2/demo.html."

.include <bsd.port.post.mk>
