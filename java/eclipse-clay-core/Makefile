# New ports collection makefile for:	eclipse-clay-core
# Date created:				January 13, 2004
# Whom:					mitsuru@riken.jp
#
# $FreeBSD$
#

PORTNAME=	clay
PORTVERSION=	1.0.5
CATEGORIES=	java devel
MASTER_SITES=	http://www.azzurri.jp/download/
PKGNAMEPREFIX=	eclipse-
PKGNAMESUFFIX=	-core
DISTNAME=	jp.azzurri.clay.core_${PORTVERSION}.bin.dist.${DISTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	mitsuru@riken.jp
COMMENT=	A database design tool for the Eclipse development environment

RUN_DEPENDS+=	${LOCALBASE}/eclipse/features/org.eclipse.gef_3.0.0/feature.xml:${PORTSDIR}/java/eclipse-gef

RESTRICTED=	Condition is not clear

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
DISABLE_SIZE?=	yes
PLIST_SUB=	RELEASEVERSION=${PORTVERSION}

DISTVERSION=	20040730

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/plugins ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/features ${PREFIX}/eclipse

.include <bsd.port.mk>
