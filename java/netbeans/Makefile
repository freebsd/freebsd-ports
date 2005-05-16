# New ports collection makefile for:	netbeans
# Date Created:				2 Jun 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	netbeans
PORTVERSION=	4.1
CATEGORIES=	java devel
MASTER_SITES=
DISTNAME=	netbeans-4_1

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A full-featured integrated environment for Java

USE_BZIP2=	yes
USE_JAVA=	1.4+
NO_BUILD=	yes
RESTRICTED=	"Restrictive license"

WRKSRC=		${WRKDIR}/netbeans

DOWNLOAD_URL?=	http://www.netbeans.info/downloads/download.php?p=1&a=bd&os=2&lang=1&rv=4.0&b_bt=2

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	You must manually fetch the source distribution (${DISTFILES}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

do-install:
		@${MKDIR} ${PREFIX}/netbeans
		@${CP} -r ${WRKSRC}/* ${PREFIX}/netbeans
		@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/netbeans
		@${LN} -sf ${PREFIX}/netbeans/bin/netbeans ${PREFIX}/bin/netbeans

.include <bsd.port.post.mk>
