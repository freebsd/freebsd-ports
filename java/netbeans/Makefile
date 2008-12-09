# New ports collection makefile for:	netbeans
# Date Created:				2 Jun 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	netbeans
PORTVERSION=	6.5
CATEGORIES=	java devel
MASTER_SITES=	http://download.netbeans.org/netbeans/6.5/final/zip/ \
    		http://dlc.sun.com.edgesuite.net/netbeans/6.5/final/zip/
DISTNAME=	netbeans-${PORTVERSION}-200811100001-ml

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A full-featured integrated environment for Java

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/netbeans

do-patch:
	@${REINPLACE_CMD} -i "" -e '19s|#||;19s|/path/to/jdk|${JAVA_HOME}|' \
	    ${WRKSRC}/etc/netbeans.conf

do-install:
	@${MKDIR} ${PREFIX}/netbeans65
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${PREFIX}/netbeans65)
	@${CHMOD} ${BINMODE} ${PREFIX}/netbeans65/bin/netbeans
	@${LN} -sf ${PREFIX}/netbeans65/bin/netbeans ${PREFIX}/bin/netbeans65

.include <bsd.port.mk>
