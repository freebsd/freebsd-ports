# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/glib-java/Makefile,v 1.4 2006/09/14 12:37:40 ahze Exp $

PORTNAME=	glib-java
PORTVERSION=	0.4.2
PORTREVISION=	3
CATEGORIES=	devel java
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Java wrapper GLib 2

DEPRECATED=	Unmaintained, outdated not depend on
EXPIRATION_DATE=	2014-25-05

OPTIONS_DEFINE=	DOCS

USES=		gmake libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
USE_GNOME=	glib20
CONFIGURE_ARGS=	--without-gcj-compile --with-jardir=${JAVAJARDIR}
CPPFLAGS+=	-I${JAVA_HOME}/include -I${JAVA_HOME}/include/freebsd
GLIB_API_VERSION=	0.4
PLIST_SUB=		GLIB_API_VERSION=${GLIB_API_VERSION} PORTNAME=${PORTNAME}
PKGMESSAGE=		${WRKDIR}/pkg-message

# Jikes related
CONFIGURE_ENV+=	BOOTCLASSPATH=${JAVA_CLASSES}
MAKE_ENV+=	BOOTCLASSPATH=${JAVA_CLASSES}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
		${WRKSRC}/configure

do-install:
	${INSTALL_LIB} ${WRKSRC}/.libs/libglibjni-${GLIB_API_VERSION}.so \
		${STAGEDIR}${PREFIX}/lib/libglibjni-${GLIB_API_VERSION}.so.1
	${LN} -sf libglibjni-${GLIB_API_VERSION}.so.1 \
		${STAGEDIR}${PREFIX}/lib/libglibjni-${GLIB_API_VERSION}.so
	${INSTALL_DATA} ${WRKSRC}/glib-java.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/jni/jg_jnu.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/jni/glib_java.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/glib${GLIB_API_VERSION}.jar ${STAGEDIR}${JAVAJARDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/macros
	${INSTALL_DATA} ${WRKSRC}/macros/* ${STAGEDIR}${PREFIX}/share/${PORTNAME}/macros
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/api
	cd ${WRKSRC}/doc/api && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/api
	${TOUCH} ${STAGEDIR}${DOCSDIR}/api/packages.html
	${TOUCH} ${STAGEDIR}${DOCSDIR}/api/serialized-form.html
.endif
	@${SED} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|g ; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%GLIB_API_VERSION%%|${GLIB_API_VERSION}|g' \
		 < ${PKGDIR}/pkg-message > ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${JAVA_PORT_VERSION} == 1.6.0
PLIST_SUB+=	JDK16="" NOTJDK16="@comment "
.else
PLIST_SUB+=	JDK16="@comment " NOTJDK16=""
.endif

.include <bsd.port.post.mk>
