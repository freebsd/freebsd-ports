# New ports collection makefile for:	eclipse
# Date created:				March 7, 2003
#
# $FreeBSD$
#

PORTNAME=	eclipse
PORTVERSION=	2.1.2
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE}
MASTER_SITE_SUBDIR=	R-2.1.2-200311030802
DISTNAME=	eclipse-sourceBuild-srcIncluded-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	java@FreeBSD.ORG
COMMENT=	An open extensible IDE for anything and nothing in particular

LIB_DEPENDS=	gtk-x11-2.0:${PORTSDIR}/x11-toolkits/gtk20
BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant \
		pkg-config:${PORTSDIR}/devel/pkgconfig

ONLY_FOR_ARCHS=	i386
USE_ZIP=	yes
USE_JAVA=	1.3+
USE_REINPLACE=	yes
NO_WRKSUBDIR=	yes

MAKE_ARGS=	ECLIPSE_BUILD=${ECLIPSE_BUILD} \
		ECLIPSE_ARCH=${ECLIPSE_ARCH} \
		ECLIPSE_OS=${ECLIPSE_OS} \
		ECLIPSE_WS=${ECLIPSE_WS} \
		JAVA_HOME=${JAVA_HOME}
MAKE_ENV=	ANT_OPTS=-Xmx256M

ECLIPSE_BUILD=	2135
ECLIPSE_OS=	freebsd
ECLIPSE_WS=	gtk
ECLIPSE_ARCH=	x86

# Here we must work around a bug that pops up when building from sources. A
# certain "run" method must be made visible in the whole class hierarchy by
# changing making it public, as documented here:
#
#   https://bugs.eclipse.org/bugs/show_bug.cgi?id=37846
#
# This access change has roots in patch-SelectionDispatchAction.java.

post-patch:
		@${FIND} ${WRKSRC} -name build.xml | ${XARGS} ${REINPLACE_CMD} 's@verbose="true"@verbose="false"@g'

		# "refactoring" begins here
		@${LN} -sf "ui refactoring" ${WRKSRC}/plugins/org.eclipse.jdt.ui/ui_refactoring
		@for FILE in $$(${FIND} -L ${WRKSRC} -print0 | ${XARGS} -0 ${GREP} -l -E "extends (SelectionDispatchAction|ReorgDestinationAction)" | grep -v " "); do \
			${REINPLACE_CMD} -e "s@protected void run(@public void run(@" \
			-e "s@protected final void run(@public final void run(@" $$FILE; \
		done

.include <bsd.port.mk>
