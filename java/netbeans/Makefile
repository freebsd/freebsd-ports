# New ports collection makefile for:	netbeans
# Date Created:				2 Jun 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	netbeans
PORTVERSION=	5.5.1
CATEGORIES=	java devel
MASTER_SITES=	http://dlc.sun.com/netbeans/download/5_5_1/fcs/200704122300/ \
		http://us1.mirror.netbeans.org/download/5_5_1/fcs/200704122300/ \
		http://us2.mirror.netbeans.org/download/5_5_1/fcs/200704122300/

DISTNAME=	netbeans-5_5_1

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A full-featured integrated environment for Java

USE_BZIP2=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/netbeans

SUB_FILES=	pkg-install pkg-deinstall

.include <bsd.port.pre.mk>

post-patch:
	@${RM} ${WRKSRC}/etc/netbeans.conf.orig

do-configure:
	@${REINPLACE_CMD} 's|%%JAVA_HOME%%|${JAVA_HOME}|' ${WRKSRC}/etc/netbeans.conf
	@${RM} ${WRKSRC}/etc/netbeans.conf.bak

do-install:
	@${MKDIR} ${PREFIX}/netbeans
	@${CP} -r ${WRKSRC}/* ${PREFIX}/netbeans
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/netbeans
	@${LN} -sf ${PREFIX}/netbeans/bin/netbeans ${PREFIX}/bin/netbeans
	@(cd ${WRKDIR}; ${FIND} -s netbeans -not -type d) >> ${TMPPLIST}
	@(cd ${WRKDIR}; ${FIND} -s -d netbeans -type d) | ${SED} -ne 's,^,@dirrm ,p' >> ${TMPPLIST}
	@(cd ${WRKDIR}; ${FIND} -s -d netbeans -type d -empty) | ${SED} -ne 's,^,@exec mkdir -p %D/,p' >> ${TMPPLIST}

.include <bsd.port.post.mk>
