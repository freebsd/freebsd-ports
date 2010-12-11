# New ports collection makefile for:	netbeans
# Date Created:				2 Jun 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	netbeans4
PORTVERSION=	4.1
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=
DISTNAME=	netbeans-4_1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A full-featured integrated environment for Java

DEPRECATED=	old, unmaintained
EXPIRATION_DATE=2011-03-31

USE_BZIP2=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes
RESTRICTED=	Restrictive license

WRKSRC=		${WRKDIR}/netbeans

SUB_FILES=	pkg-install pkg-deinstall

DOWNLOAD_URL?=	http://www.netbeans.info/downloads/download.php?p=1&a=bd&os=1&lang=1&rv=4.1&b_bt=2

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE=		you must manually fetch the source distribution (${DISTFILES}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

post-patch:
	@${RM} ${WRKSRC}/etc/netbeans.conf.orig

do-configure:
	@${REINPLACE_CMD} 's|%%JAVA_HOME%%|${JAVA_HOME}|' ${WRKSRC}/etc/netbeans.conf
	@${RM} ${WRKSRC}/etc/netbeans.conf.bak

do-install:
	@${MKDIR} ${PREFIX}/netbeans4
	@${CP} -r ${WRKSRC}/* ${PREFIX}/netbeans4
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/netbeans4
	@${LN} -sf ${PREFIX}/netbeans4/bin/netbeans ${PREFIX}/bin/netbeans4
	@(cd ${WRKDIR}; ${FIND} -s netbeans -not -type d) | ${SED} -ne 's,^netbeans,netbeans4,p' >> ${TMPPLIST}
	@(cd ${WRKDIR}; ${FIND} -s -d netbeans -type d) | ${SED} -ne 's,^netbeans,netbeans4,' -ne 's,^,@dirrm ,p' >> ${TMPPLIST}
	@(cd ${WRKDIR}; ${FIND} -s -d netbeans -type d -empty) | ${SED} -ne 's,^netbeans,netbeans4,' -ne 's,^,@exec mkdir -p %D/,p' >> ${TMPPLIST}

.include <bsd.port.post.mk>
