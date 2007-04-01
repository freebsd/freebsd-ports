# New ports collection makefile for:	eclipse support for Jad
# Date created:				Tue Aug 15 21:22:20 UTC 2006
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jad
PORTVERSION=	3.2.4
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jadclipse
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
JAVA_VERSION=	1.4+

PLIST_FILES=	eclipse/plugins/${DISTNAME}${EXTRACT_SUFX}

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/eclipse/plugins
	@${INSTALL_DATA} ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX} ${PREFIX}/eclipse/plugins

.include <bsd.port.mk>
