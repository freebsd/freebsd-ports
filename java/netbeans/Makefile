# New ports collection makefile for:	netbeans
# Date Created:				2 Jun 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	netbeans
PORTVERSION=	6.7
CATEGORIES=	java devel
MASTER_SITES=	http://www.mirrorservice.org/sites/download.netbeans.org/6.7/zip/ \
    		http://download.netbeans.org/netbeans/6.7/final/zip/ \
    		http://dlc.sun.com.edgesuite.net/netbeans/6.7/final/zip/
DISTNAME=	netbeans-${PORTVERSION}-200906241340-ml

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A full-featured integrated environment for Java

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/netbeans

post-patch:
	@${REINPLACE_CMD} -i "" -e '19s|#||;19s|/path/to/jdk|${JAVA_HOME}|' \
	    ${WRKSRC}/etc/netbeans.conf
	@${REINPLACE_CMD} -i "" -e 's|%%GCONFTOOL2%%|${LOCALBASE}/bin/gconftool-2|g; \
	    s|%%GREP%%|${GREP}|g;s|%%SED%%|${SED}|g;s|%%FGREP%%|`which fgrep`|g;s|%%AWK%%|${AWK}|g' \
	    ${WRKSRC}/platform10/lib/nbexec && \
	    ${RM} ${WRKSRC}/platform10/lib/nbexec.orig

do-install:
	@${MKDIR} ${PREFIX}/netbeans67
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${PREFIX}/netbeans67)
	@${CHMOD} ${BINMODE} ${PREFIX}/netbeans67/bin/netbeans
	@${LN} -sf ${PREFIX}/netbeans67/bin/netbeans ${PREFIX}/bin/netbeans67

.include <bsd.port.mk>
