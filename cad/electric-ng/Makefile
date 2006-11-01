# New ports collection makefile for:	electric-ng
# Date created:		2006-07-14
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	electric-ng
PORTVERSION=	8.04
CATEGORIES=	cad java
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME:S/-ng//}
DISTNAME=	electric-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A sophisticated VLSI design system

USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	yes
PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE} \
		bin/electric-ng
SUB_LIST+=	LIBFILES="${LIBFILES}" \
		JARFILE="${JARFILE}"
SUB_FILES=	electric-ng

OPTIONS=	BSH "Enable embedded java interpreter via BSH" off

JARFILE=	${DISTNAME}${EXTRACT_SUFX}

.include <bsd.port.pre.mk>

.if exists(${JAVALIBDIR}/bsh.jar)
WITH_BSH=	yes
.endif
.if defined(WITH_BSH)
RUN_DEPENDS+=	${JAVALIBDIR}/bsh.jar:${PORTSDIR}/java/bsh
LIBFILES+=	bsh
.endif

do-install:
	@${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${JARFILE} ${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/electric-ng ${PREFIX}/bin

.include <bsd.port.post.mk>
