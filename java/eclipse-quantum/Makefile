# New ports collection makefile for:	eclipse-quantum
# Date created:				July 30, 2004
# Whom:					gldisater@gldis.ca
#
# $FreeBSD$
#

PORTNAME=	quantum
PORTVERSION=	3.0.1
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-plugin/${PORTVERSION}
PKGNAMEPREFIX=	eclipse-
DISTNAME=	com.quantum.feature_${PORTVERSION}.bin.dist
DIST_SUBDIR=	eclipse

MAINTAINER=	freebsd-eclipse@FreeBSD.org
COMMENT=	Database access and SQL editor for the Eclipse IDE

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse \
                ${LOCALBASE}/eclipse/features/org.eclipse.gef_3.3.2.v20080129/feature.xml:${PORTSDIR}/java/eclipse-gef

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_EXTRACT=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_ZIP=	yes
PLIST_SUB+=	VERSION=${PORTVERSION}

post-extract:
	@${RM} ${WRKSRC}/plugins/com.quantum.Quantum_${PORTVERSION}/icons/Thumbs.db
	@${RM} ${WRKSRC}/plugins/com.quantum.Quantum_${PORTVERSION}/icons/unused/Thumbs.db
	@${RM} -rf ${WRKSRC}/plugins/com.quantum.Quantum_${PORTVERSION}/icons/.xvpics

do-install:
	@${MKDIR} ${PREFIX}/eclipse
	@${CP} -r ${WRKSRC}/plugins ${PREFIX}/eclipse
	@${CP} -r ${WRKSRC}/features ${PREFIX}/eclipse

.include <bsd.port.mk>
