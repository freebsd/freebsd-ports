# New ports collection makefile for:	netbeans
# Date Created:				15 May 2007
# Whom:				 	Nemo Liu <nemoliu@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	netbeans55
PORTVERSION=	5.5
CATEGORIES=	java devel
MASTER_SITES=	http://us2.mirror.netbeans.org/download/5_5/mlfcs/200612070100/
DISTNAME=	netbeans-5_5

MAINTAINER=	nemoliu@gmail.com
COMMENT=	A free and open-source IDE for Java

USE_BZIP2=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes
RESTRICTED=	Restrictive license

WRKSRC=		${WRKDIR}/netbeans

SUB_FILES=	pkg-install pkg-deinstall

#DOWNLOAD_URL?=	http://www.netbeans.info/downloads/index.php

.include <bsd.port.pre.mk>

#.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
#IGNORE=		you must manually fetch the source distribution (${DISTFILES}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
#.endif

post-patch:
	@${RM} ${WRKSRC}/etc/netbeans.conf.orig

do-configure:
	@${REINPLACE_CMD} 's|%%JAVA_HOME%%|${JAVA_HOME}|' ${WRKSRC}/etc/netbeans.conf
	@${RM} ${WRKSRC}/etc/netbeans.conf.bak

do-install:
	@${MKDIR} ${PREFIX}/netbeans55
	@${CP} -r ${WRKSRC}/* ${PREFIX}/netbeans55
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/netbeans55
	@${LN} -sf ${PREFIX}/netbeans55/bin/netbeans ${PREFIX}/bin/netbeans55
	@(cd ${WRKDIR}; ${FIND} -s netbeans -not -type d) | ${SED} -ne 's,^netbeans,netbeans55,p' >> ${TMPPLIST}
	@(cd ${WRKDIR}; ${FIND} -s -d netbeans -type d) | ${SED} -ne 's,^netbeans,netbeans55,' -ne 's,^,@dirrm ,p' >> ${TMPPLIST}
	@(cd ${WRKDIR}; ${FIND} -s -d netbeans -type d -empty) | ${SED} -ne 's,^netbeans,netbeans55,' -ne 's,^,@exec ${MKDIR} %D/,p' >> ${TMPPLIST}

.include <bsd.port.post.mk>
