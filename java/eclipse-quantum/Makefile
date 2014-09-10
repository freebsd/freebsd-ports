# Created by: gldisater@gldis.ca
# $FreeBSD$

PORTNAME=	quantum
PORTVERSION=	3.0.1
PORTREVISION=	5
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-plugin/${PORTVERSION}
PKGNAMEPREFIX=	eclipse-
DISTNAME=	com.quantum.feature_${PORTVERSION}.bin.dist
DIST_SUBDIR=	eclipse

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Database access and SQL editor for the Eclipse IDE

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse \
                ${LOCALBASE}/share/eclipse/dropins/gef:${PORTSDIR}/java/eclipse-gef

USES=		zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_EXTRACT=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
PLIST_SUB+=	VERSION=${PORTVERSION}

post-extract:
	@${RM} ${WRKSRC}/plugins/com.quantum.Quantum_${PORTVERSION}/icons/Thumbs.db
	@${RM} ${WRKSRC}/plugins/com.quantum.Quantum_${PORTVERSION}/icons/unused/Thumbs.db
	@${RM} -rf ${WRKSRC}/plugins/com.quantum.Quantum_${PORTVERSION}/icons/.xvpics

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/eclipse
	@${CP} -r ${WRKSRC}/plugins ${STAGEDIR}${PREFIX}/lib/eclipse
	@${CP} -r ${WRKSRC}/features ${STAGEDIR}${PREFIX}/lib/eclipse

.include <bsd.port.mk>
