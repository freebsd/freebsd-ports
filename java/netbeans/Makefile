# New ports collection makefile for:	netbeans
# Date Created:				2 Jun 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	netbeans
PORTVERSION=	3.4.1
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	# http://www.netbeans.org/download/release341/night/build200301202341/
DISTNAME=	NetBeansIDE-release341

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A full-featured integrated environment for Java

USE_BZIP2=	yes
USE_JAVA=	1.3+
NO_BUILD=	yes
RESTRICTED=	"Restrictive license"

WRKSRC=		${WRKDIR}/netbeans

DOWNLOAD_URL?=	http://www.netbeans.org/download/dev/daily/build200306020100/platform-build-tar-bz2.html

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	You must manually fetch the source distribution (${DISTFILES}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

do-install:
		@${MKDIR} ${PREFIX}/netbeans
		@${CP} -r ${WRKSRC}/* ${PREFIX}/netbeans
		@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/netbeans
		@${LN} -sf ${PREFIX}/netbeans/bin/runide.sh ${PREFIX}/bin/netbeans

.include <bsd.port.post.mk>
