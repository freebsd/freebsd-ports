# New ports collection Makefile for:	netbeans-devel
# Date created:				15 August 2008
# Whom:					gahr
#
# $FreeBSD$

PORTNAME=	netbeans
DISTVERSION=	7.0beta2
CATEGORIES=	java devel
MASTER_SITES=	http://dlc.sun.com.edgesuite.net/netbeans/7.0/beta2/zip/
PKGNAMESUFFIX=	-devel
DISTNAME=	netbeans-${DISTVERSION}-201102140001-ml

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A full-featured integrated environment for Java

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/netbeans
PREFIXDIR=	${PREFIX}/netbeans70

#IGNORE=		No development version available right now. Please use java/netbeans instead.

do-patch:
	@${REINPLACE_CMD} -i "" -e '19s|#||;19s|/path/to/jdk|${JAVA_HOME}|' \
	    ${WRKSRC}/etc/netbeans.conf

do-install:
	@${MKDIR} ${PREFIXDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${PREFIXDIR})
	@${CHMOD} ${BINMODE} ${PREFIXDIR}/bin/netbeans
	@${LN} -sf ${PREFIXDIR}/bin/netbeans ${PREFIX}/bin/netbeans70

.include <bsd.port.mk>
