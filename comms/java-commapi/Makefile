# Created by: Ari Suutari <ari.suutari@syncrontech.com>
# $FreeBSD$

PORTNAME=	java-commapi
PORTVERSION=	2.0.3
PORTREVISION=	4
CATEGORIES=	comms java
MASTER_SITES=	#
DISTNAME=	comm${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sun's Java Communications API

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+

NO_CDROM=	Sun has a funky license for this software
RESTRICTED=	no commercial use
NO_BUILD=	YES

WRKSRC=		${WRKDIR}
DISTDESCR=	"the Java Communications API ${PORTVERSION} for Generic Platform"
DOWNLOAD_URL=	"https://cds.sun.com/is-bin/INTERSHOP.enfinity/WFS/CDS-CDS_SMI-Site/en_US/-/USD/ViewProductDetail-Start?ProductRef=JAVACOMM-3.0.1-LX-SP-G-F@CDS-CDS_SMI"
PORTDESTDIR=	${STAGEDIR}${JAVA_HOME}/jre/lib/ext
DISTFILE=	${DISTNAME}${EXTRACT_SUFX}
DISTPATH=	${DISTDIR}/${DISTFILE}

PLIST_SUB+=	JAVA_HOME=${JAVA_HOME:S/${PREFIX}\///}
PLIST_FILES+=	%%JAVA_HOME%%/jre/lib/ext/comm.jar

.include <bsd.port.pre.mk>

.if !exists(${DISTPATH})
IGNORE=You must manually fetch ${DISTDESCR} (${DISTFILE}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

do-install:
	@${ECHO} -n ">> Copying comm.jar to ${PORTDESTDIR}..."
	@${MKDIR} ${PORTDESTDIR}
	@${INSTALL_DATA} ${WRKSRC}/comm.jar ${PORTDESTDIR}
	@${ECHO} " [ DONE ]"

.include <bsd.port.post.mk>
