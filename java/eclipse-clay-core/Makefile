# New ports collection makefile for:	eclipse-clay-core
# Date created:				January 13, 2004
# Whom:					mitsuru@riken.jp
#
# $FreeBSD$
#

PORTNAME=	clay
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=
PKGNAMEPREFIX=	eclipse-
PKGNAMESUFFIX=	-core
DISTNAME=	jp.azzurri.clay.core_${PORTVERSION}.bin.dist.${DISTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	mitsuru@riken.jp
COMMENT=	A database design tool for the Eclipse development environment

RUN_DEPENDS+=	${LOCALBASE}/eclipse/features/org.eclipse.gef_3.0.1/feature.xml:${PORTSDIR}/java/eclipse-gef

RESTRICTED=	License agreement is required to download.

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
DISABLE_SIZE?=	yes
PLIST_SUB=	RELEASEVERSION=${PORTVERSION}

DISTVERSION=	20041231

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/jp.azzurri.clay.core_${PORTVERSION}.bin.dist.${DISTVERSION}.zip)
IGNORE='You must manually fetch the tarball from http://www.azzurri.jp/en/software/clay/download.jsp and place it in ${DISTDIR}/${DIST_SUBDIR} then run make again.'
.endif

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/plugins ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/features ${PREFIX}/eclipse

.include <bsd.port.post.mk>
