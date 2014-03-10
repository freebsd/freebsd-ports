# Created by: gahr
# $FreeBSD$

PORTNAME=	netbeans
DISTVERSION=	8.0beta
CATEGORIES=	java devel
MASTER_SITES=	http://dlc.sun.com.edgesuite.net/netbeans/8.0/beta/zip/
PKGNAMESUFFIX=	-devel
DISTNAME=	netbeans-${DISTVERSION}-201401141042

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Full-featured integrated environment for Java

LICENSE=	CDDL GPLv2
LICENSE_COMB=	dual

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.7+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/netbeans
PREFIXDIR=	${PREFIX}/netbeans-${PORTVERSION}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

#IGNORE=		No development version available right now. Please use java/netbeans instead.

post-patch:
	@${REINPLACE_CMD} -e '57s|#||;57s|/path/to/jdk|${JAVA_HOME}|' \
	    ${WRKSRC}/etc/netbeans.conf
	${RM} ${WRKSRC}/bin/netbeans.orig

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIXDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIXDIR}
	@${CHMOD} ${BINMODE} ${STAGEDIR}${PREFIXDIR}/bin/netbeans
	${LN} -sf ${PREFIXDIR}/bin/netbeans ${STAGEDIR}${PREFIX}/bin/netbeans-${PORTVERSION}

.include <bsd.port.mk>
