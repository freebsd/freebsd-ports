# New ports collection makefile for:	eclipse-cdt
# Date created:				March 1, 2004
# Whom:					gldisater@gldis.ca
#
# $FreeBSD$
#

PORTNAME=	cdt
PORTVERSION=	2.0
CATEGORIES=	java devel
MASTER_SITES=	http://download.eclipse.org/tools/cdt/releases/new/zips/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	org.eclipse.cdt-${PORTVERSION}-linux.${ECLIPSE_WS}.${ECLIPSE_ARCH}
DIST_SUBDIR=	eclipse

MAINTAINER=	java@freebsd.org
COMMENT=	C/C++ IDE for Eclipse

RUN_DEPENDS=	${LOCALBASE}/eclipse/plugins/org.eclipse.swt.${ECLIPSE_WS}_3.0.0/ws/${ECLIPSE_WS}/swt.jar:${ECLIPSE_TARGET}

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+

ECLIPSE_ARCH=x86
ECLIPSE_TARGET=	${PORTSDIR}/java/eclipse

.if defined(WITH_MOTIF)
ECLIPSE_WS=	motif
USE_MOTIF=	yes
PLIST_SUB=	WITH_GTK="@comment "
.else
ECLIPSE_WS=	gtk
USE_GTK=	yes
PLIST_SUB=	WITH_GTK=""
.endif

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/plugins  ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/features ${PREFIX}/eclipse

.include <bsd.port.mk>
