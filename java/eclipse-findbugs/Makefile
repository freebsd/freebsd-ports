# New ports collection makefile for:	findbugs eclipse plugin
# Date created:		Dom  1 Abr 2007 22:42:25 UTC
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	findbugs
DISTVERSION=	1.3.2.20080222
PORTREVISION=	3
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20eclipse%20plugin/1.3.2
PKGNAMEPREFIX=	eclipse-
DISTNAME=	edu.umd.cs.findbugs.plugin.eclipse_${DISTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Eclipse plug-in that provides FindBugs support

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native

PLIST_DIRS=	\
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/META-INF \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/plugin \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/icons \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%
#
PLIST_FILES=	\
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/META-INF/MANIFEST.MF \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/FindBugs.png \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/Fortify.png \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/RELEASENOTES \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/about.html \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/about.ini \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/about.properties \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/annotations.jar \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/asm-3.0.jar \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/asm-commons-3.0.jar \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/asm-tree-3.0.jar \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/bcel.jar \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/dom4j-full.jar \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/findbugs-ant.jar \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/findbugs-plugin.jar \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/findbugs.jar \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/icons/annotationsView.png \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/icons/bug.gif \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/icons/buggy-tiny-blue.png \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/icons/buggy-tiny-green.png \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/icons/buggy-tiny-orange.png \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/icons/buggy-tiny-yellow.png \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/icons/buggy-tiny.png \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/icons/bugview.gif \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/icons/detailsView.png \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/icons/refresh.gif \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/icons/runFindbugs.png \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/icons/treeView.png \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/icons/warning.png \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/jsr305.jar \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/plugin.properties \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/plugin.xml \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/plugin/coreplugin.jar \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/plugin/findbugs-resolutions.xml \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/plugin_fr.properties \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/plugin_ja.properties \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/smallBuggy.png \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/umdFindbugs.png \
	%%ECLIPSE_PLUGINS%%/%%DISTNAME%%/welcome.xml
#
PLIST_SUB=	\
	ECLIPSE_PLUGINS="lib/eclipse/plugins" \
	DISTNAME="${DISTNAME}"

post-extract:
	@${RM} -Rf ${WRKSRC}/src

do-install:
		@${MKDIR} ${PREFIX}/lib/eclipse/plugins
		@(cd ${WRKDIR} && \
			${FIND} -s $$(${BASENAME} ${WRKSRC}) -type d \
				-exec ${MKDIR} "${PREFIX}/lib/eclipse/plugins/{}" \; && \
			${FIND} -s $$(${BASENAME} ${WRKSRC}) -not -type d \
				-exec ${INSTALL_DATA} "{}" "${PREFIX}/lib/eclipse/plugins/{}" \; \
		)

.include <bsd.port.mk>
