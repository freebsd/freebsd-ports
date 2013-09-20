# Created by: gahr
# $FreeBSD$

PORTNAME=	netbeans
DISTVERSION=	7.3beta2
CATEGORIES=	java devel
MASTER_SITES=	http://dlc.sun.com.edgesuite.net/netbeans/7.3/beta2/zip/
PKGNAMESUFFIX=	-devel
DISTNAME=	netbeans-${DISTVERSION}-201211062253

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A full-featured integrated environment for Java

LICENSE=	CDDL GPLv2
LICENSE_COMB=	dual

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.7+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/netbeans
PREFIXDIR=	${PREFIX}/netbeans-${PORTVERSION}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

IGNORE=		No development version available right now. Please use java/netbeans instead.

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -i "" -e '19s|#||;19s|/path/to/jdk|${JAVA_HOME}|' \
	    ${WRKSRC}/etc/netbeans.conf
	${RM} ${WRKSRC}/bin/netbeans.orig

do-install:
	@${MKDIR} ${PREFIXDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${PREFIXDIR})
	@${CHMOD} ${BINMODE} ${PREFIXDIR}/bin/netbeans
	@${LN} -sf ${PREFIXDIR}/bin/netbeans ${PREFIX}/bin/netbeans-${PORTVERSION}

.include <bsd.port.mk>
