# New ports collection makefile for:   libglade-java
# Date created:        28 February 2004
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libglade-java
PORTVERSION=	2.4.0
PORTREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.4
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Java wrapper for libglade

BUILD_DEPENDS=	${LOCALBASE}/share/java/classes/gtk${GTK_API_VERSION}-${GTK_JAVA_VERSION}.jar:${PORTSDIR}/x11-toolkits/libgtk-java \
		${LOCALBASE}/share/java/classes/gnome${GNOME_API_VERSION}-${GNOME_JAVA_VERSION}.jar:${PORTSDIR}/x11/libgnome-java
RUN_DEPENDS=	${LOCALBASE}/share/java/classes/gtk${GTK_API_VERSION}-${GTK_JAVA_VERSION}.jar:${PORTSDIR}/x11-toolkits/libgtk-java \
		${LOCALBASE}/share/java/classes/gnome${GNOME_API_VERSION}-${GNOME_JAVA_VERSION}.jar:${PORTSDIR}/x11/libgnome-java

USE_BZIP2=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.2+
JAVA_OS=	native
USE_GNOME=	gnomehack libglade2
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--without-gcj-compile \
		--with-java-prefix=${JAVA_HOME}
CONFIGURE_ENV=	DB2="/dev/null"

GLADE_API_VERSION=	2.4
GTK_API_VERSION=	2.4
GNOME_API_VERSION=	2.6
GTK_JAVA_VERSION=	2.4.0
GNOME_JAVA_VERSION=	2.6.0
VERSION=		2.4.0
PLIST_SUB=		GLADE_API_VERSION=${GLADE_API_VERSION} \
			PORTVERSION=${VERSION}

PKGMESSAGE=		${WRKDIR}/pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|^GTKJAR=.*|GTKJAR=${LOCALBASE}/share/java/classes/gtk${GTK_API_VERSION}-${GTK_JAVA_VERSION}.jar| ; \
		s|^GNOMEJAR=.*|GNOMEJAR=${LOCALBASE}/share/java/classes/gnome${GNOME_API_VERSION}-${GNOME_JAVA_VERSION}.jar|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|@gtkapiversion@|${GTK_API_VERSION}|g ; \
		s|@apiversion@|${GLADE_API_VERSION}|g ; \
		s|@version@|${VERSION}|g' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/src/java/org/gnu/glade/LibGlade.java.in

do-install:
	${MKDIR} ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/libgladejava${GLADE_API_VERSION}.so.${VERSION} \
		${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libgladejava${GLADE_API_VERSION}.so.${VERSION} ${PREFIX}/lib/libgladejava${GLADE_API_VERSION}.so
	${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/glade${GLADE_API_VERSION}-${VERSION}.jar \
		${JAVAJARDIR}
	${LN} -sf ${JAVAJARDIR}/lib/glade${GLADE_API_VERSION}-${VERSION}.jar \
		${JAVAJARDIR}/glade${GLADE_API_VERSION}.jar

post-install:
	@${SED} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|g ; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%GLADE_API_VERSION%%|${GLADE_API_VERSION}|g' \
		 < ${PKGDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
