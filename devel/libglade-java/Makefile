# New ports collection makefile for:   libglade-java
# Date created:        28 February 2004
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/libglade-java/Makefile,v 1.8 2005/10/29 22:06:06 marcus Exp $
#

PORTNAME=	libglade-java
PORTVERSION=	2.12.3
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.12
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Java wrapper for libglade

BUILD_DEPENDS=	${JAVALIBDIR}/gtk${GTK_API_VERSION}.jar:${PORTSDIR}/x11-toolkits/libgtk-java \
		${JAVALIBDIR}/gnome${GNOME_API_VERSION}.jar:${PORTSDIR}/x11/libgnome-java
RUN_DEPENDS=	${JAVALIBDIR}/gtk${GTK_API_VERSION}.jar:${PORTSDIR}/x11-toolkits/libgtk-java \
		${JAVALIBDIR}/gnome${GNOME_API_VERSION}.jar:${PORTSDIR}/x11/libgnome-java

USE_BZIP2=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_JAVA=	yes
USE_GCC=	3.4+
JAVA_VERSION=	1.2+
JAVA_OS=	native
USE_GNOME=	gnomehack libglade2
CONFIGURE_ARGS=	--without-gcj-compile
CONFIGURE_ENV=	CPPFLAGS="-I${JAVA_HOME}/include -I${JAVA_HOME}/include/freebsd"

GLADE_API_VERSION=	2.12
GTK_API_VERSION=	2.8
GNOME_API_VERSION=	2.12
PLIST_SUB=		GLADE_API_VERSION=${GLADE_API_VERSION} \
			PORTNAME=${PORTNAME}

PKGMESSAGE=		${WRKDIR}/pkg-message

do-install:
	${MKDIR} ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/.libs/libgladejni-${GLADE_API_VERSION}.so \
		${PREFIX}/lib/libgladejni-${GLADE_API_VERSION}.so.1
	${LN} -sf ${PREFIX}/lib/libgladejni-${GLADE_API_VERSION}.so.1 \
		${PREFIX}/lib/libgladejni-${GLADE_API_VERSION}.so
	${MKDIR} ${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/glade-java.pc	${PREFIX}/libdata/pkgconfig
	${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/glade${GLADE_API_VERSION}.jar ${JAVAJARDIR}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/api
	cd ${WRKSRC}/doc/api && ${FIND} . | ${CPIO} -pdmu ${DOCSDIR}/api
	${MKDIR} ${DOCSDIR}/examples
	cd ${WRKSRC}/doc/examples && ${FIND} . \
		| ${CPIO} -pdmu ${DOCSDIR}/examples
.endif
	@${SED} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|g ; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%GLADE_API_VERSION%%|${GLADE_API_VERSION}|g' \
		 < ${PKGDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
