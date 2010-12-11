# New ports collection makefile for:	netbeans
# Date Created:				2 Jun 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	netbeans3
PORTVERSION=	3.6
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=
DISTNAME=	netbeans-3_6

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

DOWNLOAD_URL?=	http://www.netbeans.org/download/release36/promoted/FCS/release36-build-tar-bz2.html

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE=		you must manually fetch the source distribution (${DISTFILES}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

post-patch:
	@${CAT} ${FILESDIR}/bin_runide.sh.diff | ${PATCH} ${WRKSRC}/bin/runide.sh
	@${RM} ${WRKSRC}/bin/runide.sh.orig

do-install:
	@${MKDIR} ${PREFIX}/netbeans3
	@${CP} -r ${WRKSRC}/* ${PREFIX}/netbeans3
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/netbeans3
	@${LN} -sf ${PREFIX}/netbeans3/bin/runide.sh ${PREFIX}/bin/netbeans3
	@(cd ${WRKDIR}; ${FIND} -s netbeans -not -type d) | ${SED} -ne 's,^netbeans,netbeans3,p' >> ${TMPPLIST}
	@(cd ${WRKDIR}; ${FIND} -s -d netbeans -type d) | ${SED} -ne 's,^netbeans,netbeans3,' -ne 's,^,@dirrm ,p' >> ${TMPPLIST}
	@(cd ${WRKDIR}; ${FIND} -s -d netbeans -type d -empty) | ${SED} -ne 's,^netbeans,netbeans3,' -ne 's,^,@exec mkdir -p %D/,p' >> ${TMPPLIST}

.include <bsd.port.post.mk>
