# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jad
PORTVERSION=	3.3.0
PORTREVISION=	5
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}clipse/${PORTNAME}clipse3.3/${PORTVERSION}%20%28for%20Eclipse%20_%3D3.3M6%29
PKGNAMEPREFIX=	eclipse-
DISTNAME=	net.sf.jadclipse_${PORTVERSION}
EXTRACT_SUFX=	.jar
DIST_SUBDIR=	eclipse
EXTRACT_ONLY=

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Jad Java decompiler plugin for the Eclipse IDE

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse \
		jad:${PORTSDIR}/java/jad

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+

PLIST_FILES=	share/eclipse/dropins/${DISTNAME}${EXTRACT_SUFX}

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/eclipse/dropins
	@${INSTALL_DATA} ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX} ${STAGEDIR}${PREFIX}/share/eclipse/dropins

.include <bsd.port.mk>
