# New ports collection makefile for:	netbeans
# Date Created:				2 Jun 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	netbeans
PORTVERSION=	3.5.1
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	# http://www.netbeans.org/download/release351/night/build200307252351/

DISTNAME=	NetBeansIDE-release351

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A full-featured integrated environment for Java

USE_BZIP2=	yes
USE_JAVA=	1.3+
NO_BUILD=	yes
RESTRICTED=	"Restrictive license"

WRKSRC=		${WRKDIR}/netbeans

DOWNLOAD_URL?=	http://www.netbeans.org/download/release351/night/build200307252351/release351-build-tar-bz2.html

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	You must manually fetch the source distribution (${DISTFILES}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

.if ${OSVERSION} >= 500000
post-patch:
		@${CAT} ${FILESDIR}/bin_runide.sh.diff | ${PATCH} ${WRKSRC}/bin/runide.sh
.endif

do-install:
		@${MKDIR} ${PREFIX}/netbeans
		@${CP} -r ${WRKSRC}/* ${PREFIX}/netbeans
		@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/netbeans
		@${LN} -sf ${PREFIX}/netbeans/bin/runide.sh ${PREFIX}/bin/netbeans

.include <bsd.port.post.mk>
