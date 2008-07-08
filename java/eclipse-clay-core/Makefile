# New ports collection makefile for:	eclipse-clay-core
# Date created:				January 13, 2004
# Whom:					mitsuru@riken.jp
#
# $FreeBSD$
#

PORTNAME=	clay
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=
PKGNAMEPREFIX=	eclipse-
PKGNAMESUFFIX=	-core
DISTNAME=	jp.azzurri.clay.core_${PORTVERSION}.bin.dist.${DISTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	mitsuru@riken.jp
COMMENT=	A database design tool for the Eclipse development environment

RUN_DEPENDS+=	${LOCALBASE}/eclipse/features/org.eclipse.gef_3.2.2.v20070208/feature.xml:${PORTSDIR}/java/eclipse-gef

RESTRICTED=	License agreement is required to download.

BROKEN=		does not package

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
DISABLE_SIZE?=	yes
PLIST_SUB=	RELEASEVERSION=${PORTVERSION}

DISTVERSION=	20070918

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/jp.azzurri.clay.core_${PORTVERSION}.bin.dist.${DISTVERSION}.zip) && !defined(PACKAGE_BUILDING)
IGNORE='You must manually fetch the tarball from http://www.azzurri.jp/en/clay/download.html and place it in ${DISTDIR}/${DIST_SUBDIR} then run make again.'
.endif

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/plugins ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/features ${PREFIX}/eclipse

.include <bsd.port.post.mk>
