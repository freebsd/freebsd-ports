# New ports collection makefile for:	netbeans
# Date Created:				2 Jun 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	netbeans
PORTVERSION=	3.4.1
CATEGORIES=	java devel
MASTER_SITES=	http://www.netbeans.org/download/release341/night/build200301202341/
DISTNAME=	NetBeansIDE-release341

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A full-featured integrated environment for Java

USE_BZIP2=	yes
USE_JAVA=	1.2+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/netbeans

do-install:
		@${MKDIR} ${PREFIX}/netbeans
		@${CP} -r ${WRKSRC}/* ${PREFIX}/netbeans
		@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/netbeans
		@${LN} -sf ${PREFIX}/netbeans/bin/runide.sh ${PREFIX}/bin/netbeans

.include <bsd.port.mk>
