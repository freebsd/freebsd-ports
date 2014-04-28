# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/libglade-java/Makefile,v 1.8 2005/10/29 22:06:06 marcus Exp $

PORTNAME=	libglade-java
PORTVERSION=	2.12.8
PORTREVISION=	6
CATEGORIES=	devel java
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Java wrapper for libglade

DEPRECATED=	Unmaintained, outdated not depend on
EXPIRATION_DATE=	2014-05-25

BUILD_DEPENDS=	${JAVALIBDIR}/gtk${GTK_API_VERSION}.jar:${PORTSDIR}/x11-toolkits/libgtk-java \
		${JAVALIBDIR}/gnome${GNOME_API_VERSION}.jar:${PORTSDIR}/x11/libgnome-java
RUN_DEPENDS=	${JAVALIBDIR}/gtk${GTK_API_VERSION}.jar:${PORTSDIR}/x11-toolkits/libgtk-java \
		${JAVALIBDIR}/gnome${GNOME_API_VERSION}.jar:${PORTSDIR}/x11/libgnome-java

USES=		gmake libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
USE_GNOME=	libglade2
CONFIGURE_ARGS=	--without-gcj-compile --with-jardir=${JAVAJARDIR}
CPPFLAGS+=	-I${JAVA_HOME}/include -I${JAVA_HOME}/include/freebsd

GLADE_API_VERSION=	2.12
GTK_API_VERSION=	2.10
GNOME_API_VERSION=	2.12
PLIST_SUB=		GLADE_API_VERSION=${GLADE_API_VERSION} \
			PORTNAME=${PORTNAME}

PKGMESSAGE=		${WRKDIR}/pkg-message

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
		${WRKSRC}/configure

do-install:
	${INSTALL_LIB} ${WRKSRC}/.libs/libgladejni-${GLADE_API_VERSION}.so \
		${STAGEDIR}${PREFIX}/lib/libgladejni-${GLADE_API_VERSION}.so.1
	${LN} -sf libgladejni-${GLADE_API_VERSION}.so.1 \
		${STAGEDIR}${PREFIX}/lib/libgladejni-${GLADE_API_VERSION}.so
	${MKDIR} ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/glade-java.pc	${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/glade${GLADE_API_VERSION}.jar ${STAGEDIR}${JAVAJARDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/api
	cd ${WRKSRC}/doc/api && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/api
	${TOUCH} ${STAGEDIR}${DOCSDIR}/api/packages.html
	${MKDIR} ${STAGEDIR}${DOCSDIR}/examples
	cd ${WRKSRC}/doc/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/examples
	@${SED} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|g ; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%GLADE_API_VERSION%%|${GLADE_API_VERSION}|g' \
		 < ${PKGDIR}/pkg-message > ${PKGMESSAGE}

.include <bsd.port.mk>
