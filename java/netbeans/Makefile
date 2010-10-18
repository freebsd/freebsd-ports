# ex:ts=8
# New ports collection makefile for:	netbeans
# Date Created:				2 Jun 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	netbeans
PORTVERSION=	6.9.1
CATEGORIES=	java devel
MASTER_SITES=	http://download.netbeans.org/netbeans/6.9.1/final/zip/ \
    		http://dlc.sun.com.edgesuite.net/netbeans/6.9.1/final/zip/
DISTNAME=	netbeans-${PORTVERSION}-201007282301-ml

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A full-featured integrated environment for Java

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/netbeans
DATADIR=	${PREFIX}/${PORTNAME}-${PORTVERSION}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -i "" -e '19s|#||;19s|/path/to/jdk|${JAVA_HOME}|' \
	    ${WRKSRC}/etc/netbeans.conf
	@${REINPLACE_CMD} -i "" -e 's|%%GCONFTOOL2%%|${LOCALBASE}/bin/gconftool-2|g; \
	    s|%%GREP%%|${GREP}|g;s|%%SED%%|${SED}|g;s|%%FGREP%%|`which fgrep`|g;s|%%AWK%%|${AWK}|g' \
	    ${WRKSRC}/platform/lib/nbexec && \
	    ${RM} ${WRKSRC}/platform/lib/nbexec.orig

do-install:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${DATADIR})
	@${CHMOD} ${BINMODE} ${DATADIR}/bin/netbeans
	@${LN} -sf ${DATADIR}/bin/netbeans ${PREFIX}/bin/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
