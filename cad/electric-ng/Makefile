# New ports collection makefile for:	electric-ng
# Date created:		2006-07-14
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	electric-ng
PORTVERSION=	8.11
PORTREVISION=	0
CATEGORIES=	cad java
MASTER_SITES=	${MASTER_SITE_GNU} \
		http://www.staticfreesoft.com/:1
MASTER_SITE_SUBDIR=	${PORTNAME:S/-ng//}
DISTNAME=	electric-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A sophisticated VLSI design system

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes
PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE} \
		bin/electric-ng
SUB_LIST+=	LIBFILES="${LIBFILES}" \
		JARFILE="${JARFILE}"
SUB_FILES=	electric-ng

OPTIONS=	BSH	"Enable embedded java interpreter via BSH"	off \
		3D	"Enable 3D visualization via Java3D"		off \
		IRSIM	"Install IRSIM plugin"				off \
		ANIM	"Install 3D animation plugin"			off \
		AXIS	"Install 3D Axis Controller plugin"		off \
		RUSSIAN	"Install Russian manual"			off

JARFILE=	${DISTNAME}${EXTRACT_SUFX}
J3DLIB=		${LOCALBASE}/share/java/java3d/jar/j3dcore.jar
PLUGINDIR=	${PREFIX}/libexec/electric/

.include <bsd.port.pre.mk>

.if exists(${JAVALIBDIR}/bsh.jar)
WITH_BSH=	yes
.endif
.if defined(WITH_BSH)
RUN_DEPENDS+=	${JAVALIBDIR}/bsh.jar:${PORTSDIR}/lang/bsh
LIBFILES+=	${JAVALIBDIR}/bsh.jar
.endif

.if defined(WITH_AXIS)
WITH_3D=	yes
PLUGINS+=	electricJava3D-8.11
.endif

.if defined(WITH_ANIM)
WITH_3D=	yes
RUN_DEPENDS+=	${JAVALIBDIR}/jmf.jar:${PORTSDIR}/java/jmf
PLUGINS+=	electricJMF-8.11
.endif

.if exists(${J3DLIB})
WITH_3D=	yes
.endif
.if defined(WITH_3D)
RUN_DEPENDS+=	${J3DLIB}:${PORTSDIR}/java/java3d
.endif

.if defined(WITH_IRSIM)
PLUGINS+=	electricIRSIM-8.11
.endif

.if defined(WITH_RUSSIAN)
PLUGINS+=	electricRussianManual-8.11
.endif

.if defined(PLUGINS)
LIBFILES+=	${PLUGINS:S,$,.jar,:S,^,${PLUGINDIR}/,}
DISTFILES=	${PLUGINS:S,$,.jar,:S,$,:1,} ${DISTNAME}${EXTRACT_SUFX}
PLIST_FILES+=	${PLUGINS:S,$,.jar,:S,^,libexec/electric/,}
.endif

do-install:
	@${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${JARFILE} ${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/electric-ng ${PREFIX}/bin

.if defined(PLUGINS)
	# Install plugins
	@${MKDIR} ${PLUGINDIR}/
	${INSTALL_DATA} ${PLUGINS:S,^,${DISTDIR}/,:S,$,.jar,} ${PLUGINDIR}/
.endif

.include <bsd.port.post.mk>
