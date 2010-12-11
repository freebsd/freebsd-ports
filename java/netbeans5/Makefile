# New ports collection makefile for:	netbeans
# Date Created:				15 May 2007
# Whom:				 	Nemo Liu <nemoliu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	netbeans5
PORTVERSION=	5
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	http://dlc.sun.com/netbeans/download/5_0/fcs/200601251500/ \
		http://us1.mirror.netbeans.org/download/5_0/fcs/200601251500/
DISTNAME=	netbeans-5_0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free and open-source IDE for Java

BROKEN=		doesn't fetch
DEPRECATED=	old, unmaintained
EXPIRATION_DATE=2011-03-31

USE_BZIP2=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes
RESTRICTED=	Restrictive license

WRKSRC=		${WRKDIR}/netbeans

SUB_FILES=	pkg-install pkg-deinstall

DOWNLOAD_URL?=	http://www.netbeans.info/downloads/index.php?rs=2

.include <bsd.port.pre.mk>

post-patch:
	@${RM} ${WRKSRC}/etc/netbeans.conf.orig

do-configure:
	@${REINPLACE_CMD} 's|%%JAVA_HOME%%|${JAVA_HOME}|' ${WRKSRC}/etc/netbeans.conf
	@${RM} ${WRKSRC}/etc/netbeans.conf.bak

do-install:
	@${MKDIR} ${PREFIX}/netbeans5
	@${CP} -r ${WRKSRC}/* ${PREFIX}/netbeans5
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/netbeans5
	@${LN} -sf ${PREFIX}/netbeans5/bin/netbeans ${PREFIX}/bin/netbeans5
	@(cd ${WRKDIR}; ${FIND} -s netbeans -not -type d) | ${SED} -ne 's,^netbeans,netbeans5,p' >> ${TMPPLIST}
	@(cd ${WRKDIR}; ${FIND} -s -d netbeans -type d) | ${SED} -ne 's,^netbeans,netbeans5,' -ne 's,^,@dirrm ,p' >> ${TMPPLIST}
	@(cd ${WRKDIR}; ${FIND} -s -d netbeans -type d -empty) | ${SED} -ne 's,^netbeans,netbeans5,' -ne 's,^,@exec ${MKDIR} %D/,p' >> ${TMPPLIST}

.include <bsd.port.post.mk>
