# New ports collection makefile for:	netbeans
# Date Created:				2 Jun 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	netbeans
PORTVERSION=	6.8
CATEGORIES=	java devel
MASTER_SITES=	http://www.mirrorservice.org/sites/download.netbeans.org/6.8/zip/ \
    		http://download.netbeans.org/netbeans/6.8/final/zip/ \
    		http://dlc.sun.com.edgesuite.net/netbeans/6.8/final/zip/
DISTNAME=	netbeans-${PORTVERSION}-200912041610-ml

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A full-featured integrated environment for Java

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/netbeans
DATADIR=	${PREFIX}/${PORTNAME}${PORTVERSION:S/.//}

post-patch:
	@${REINPLACE_CMD} -i "" -e '19s|#||;19s|/path/to/jdk|${JAVA_HOME}|' \
	    ${WRKSRC}/etc/netbeans.conf
	@${REINPLACE_CMD} -i "" -e 's|%%GCONFTOOL2%%|${LOCALBASE}/bin/gconftool-2|g; \
	    s|%%GREP%%|${GREP}|g;s|%%SED%%|${SED}|g;s|%%FGREP%%|`which fgrep`|g;s|%%AWK%%|${AWK}|g' \
	    ${WRKSRC}/platform11/lib/nbexec && \
	    ${RM} ${WRKSRC}/platform11/lib/nbexec.orig

do-install:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${DATADIR})
	@${CHMOD} ${BINMODE} ${DATADIR}/bin/netbeans
	@${LN} -sf ${DATADIR}/bin/netbeans ${PREFIX}/bin/${PORTNAME}${PORTVERSION:S/.//}

.include <bsd.port.mk>
