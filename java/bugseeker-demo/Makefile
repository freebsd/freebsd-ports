# New ports collection makefile for:   bugseeker
# Date created:        22 December 2000
# Whom:                Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bugseeker-demo
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	http://www.karmira.com/products/bugseeker2/download/
DISTNAME=	bugseeker2demo

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	znerd
PATCHFILES=	bugseeker2demo.sh.diff

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A debugger for Java software

BROKEN=		Unfetchable
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

USE_JAVA=	1.3+

NO_BUILD=	YES

WRKSRC=		${WRKDIR}/${DISTNAME}
PORTDESTDIR=	${PREFIX}/${PORTNAME}
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
	@${ECHO_CMD} "${PORTTITLE} has been installed in ${PORTDESTDIR}."
	@${ECHO_CMD} "If you don't have a trial license yet, then you can get a 30-day license at:"
	@${ECHO_CMD} "http://www.karmira.com/products/bugseeker2/demo.html."

.include <bsd.port.post.mk>
