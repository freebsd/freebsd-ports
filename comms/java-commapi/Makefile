# New ports collection makefile for:    Java Commapi
# Date created:		2001/07/01
# Whom:			Ari Suutari <ari.suutari@syncrontech.com>
#
# $FreeBSD$
#

PORTNAME=	java-commapi
PORTVERSION=	2.0.2
CATEGORIES=	comms java
MASTER_SITES=	#
DISTNAME=	javax_comm-${PORTVERSION:S/./_/g}-solsparc
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ari.suutari@syncrontech.com

RUN_DEPENDS=	${LOCALBASE}/jdk1.3.1/bin/java:${PORTSDIR}/java/jdk13

NO_CDROM=	"Sun has a funky license for this software"
RESTRICTED=	"no commercial use"
NO_BUILD=	YES

WRKSRC=		${WRKDIR}/commapi
DISTDESCR=	"the Java Communications API ${PORTVERSION} for Solaris/SPARC archive"
DOWNLOAD_URL=	"http://java.sun.com/Download4?config-file=javacomm-${PORTVERSION:S/./_/g}.config\&platform=solsparc\&button=continue"
PORTDESTDIR=	${PREFIX}/jdk1.3.1/jre/lib/ext
DISTFILE=	${DISTNAME}${EXTRACT_SUFX}
DISTPATH=	${DISTDIR}/${DISTFILE}

.if defined(BATCH) || defined(PACKAGE_BUILDING)
IGNORE=		"Should be fetched manually"
.endif

.include <bsd.port.pre.mk>

.if !exists(${DISTPATH})
IGNORE=You must manually fetch ${DISTDESCR} (${DISTFILE}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again.
.endif

do-install:
	@${ECHO} -n ">> Copying comm.jar to ${PORTDESTDIR}..."
	@${INSTALL_DATA} ${WRKSRC}/comm.jar ${PORTDESTDIR}
	@${ECHO} " [ DONE ]"

.include <bsd.port.post.mk>
