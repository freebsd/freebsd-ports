# New ports collection makefile for:    Java Commapi
# Date created:		2001/07/01
# Whom:			Ari Suutari <ari.suutari@syncrontech.com>
#
# $FreeBSD$
#

PORTNAME=	java-commapi
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	comms java
MASTER_SITES=	#
DISTNAME=	javax_comm-${PORTVERSION:S/./_/g}-solsparc
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ari.suutari@syncrontech.com
COMMENT=	Sun's Java Communications API

USE_JAVA=	1.3+

NO_CDROM=	"Sun has a funky license for this software"
RESTRICTED=	"no commercial use"
NO_BUILD=	YES

WRKSRC=		${WRKDIR}/commapi
DISTDESCR=	"the Java Communications API ${PORTVERSION} for Solaris/SPARC"
DOWNLOAD_URL=	"http://java.sun.com/products/javacomm/"
PORTDESTDIR=	${JAVA_HOME}/jre/lib/ext
DISTFILE=	${DISTNAME}${EXTRACT_SUFX}
DISTPATH=	${DISTDIR}/${DISTFILE}

PLIST_SUB+=	JAVA_HOME=${JAVA_HOME:S/${PREFIX}\///}

.if defined(BATCH) || defined(PACKAGE_BUILDING)
IGNORE=		"Should be fetched manually"
.endif

.include <bsd.port.pre.mk>

.if !exists(${DISTPATH})
IGNORE=You must manually fetch ${DISTDESCR} (${DISTFILE}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

do-install:
	@${ECHO} -n ">> Copying comm.jar to ${PORTDESTDIR}..."
	@${INSTALL_DATA} ${WRKSRC}/comm.jar ${PORTDESTDIR}
	@${ECHO} " [ DONE ]"

.include <bsd.port.post.mk>
