# New ports collection Makefile for:	netbeans-devel
# Date created:				15 August 2008
# Whom:					gahr
#
# $FreeBSD$

PORTNAME=	netbeans
PORTVERSION=	6.5
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	http://download.netbeans.org/netbeans/6.5/rc/zip/
PKGNAMESUFFIX=	-devel
DISTNAME=	netbeans-${PORTVERSION}rc2-200810270001-ml

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A full-featured integrated environment for Java

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/netbeans

IGNORE=		No development version available right now. Please use java/netbeans instead.

do-patch:
	@${REINPLACE_CMD} -i "" -e '19s|#||;19s|/path/to/jdk|${JAVA_HOME}|' \
	    ${WRKSRC}/etc/netbeans.conf

do-install:
	@${MKDIR} ${PREFIX}/netbeans65
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${PREFIX}/netbeans65)
	@${CHMOD} ${BINMODE} ${PREFIX}/netbeans65/bin/netbeans
	@${LN} -sf ${PREFIX}/netbeans65/bin/netbeans ${PREFIX}/bin/netbeans65

.include <bsd.port.mk>
