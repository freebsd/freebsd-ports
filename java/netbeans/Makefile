# ex:ts=8
# New ports collection makefile for:	netbeans
# Date Created:				2 Jun 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	netbeans
PORTVERSION=	7.0.1
CATEGORIES=	java devel
MASTER_SITES=	http://download.netbeans.org/netbeans/${PORTVERSION}/final/zip/ \
    		http://dlc.sun.com.edgesuite.net/netbeans/${PORTVERSION}/final/zip/
DISTNAME=	netbeans-${PORTVERSION}-201107282000-ml

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
	    ${WRKSRC}/platform/lib/nbexec
	@${FIND} ${WRKSRC} -name "*.orig" -delete

do-install:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${DATADIR})
	@${CHMOD} ${BINMODE} ${DATADIR}/bin/netbeans
	@${LN} -sf ${DATADIR}/bin/netbeans ${PREFIX}/bin/${PORTNAME}-${PORTVERSION}

post-install:
	@${CHMOD} ${BINMODE} ${DATADIR}/java/maven/bin/mvn

.include <bsd.port.mk>
