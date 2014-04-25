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
EXPIRATION_DATE=	2014-25-05

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

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
		${WRKSRC}/configure

do-install:
	${INSTALL_LIB} ${WRKSRC}/.libs/libgladejni-${GLADE_API_VERSION}.so \
		${STAGEDIR}${PREFIX}/lib/libgladejni-${GLADE_API_VERSION}.so.1
	${LN} -sf libgladejni-${GLADE_API_VERSION}.so.1 \
		${STAGEDIR}${PREFIX}/lib/libgladejni-${GLADE_API_VERSION}.so
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
	${TOUCH} ${DOCSDIR}/api/packages.html
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
