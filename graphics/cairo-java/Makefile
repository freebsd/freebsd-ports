# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/graphics/cairo-java/Makefile,v 1.4 2006/09/14 12:47:28 ahze Exp $

PORTNAME=	cairo-java
PORTVERSION=	1.0.8
PORTREVISION=	4
CATEGORIES=	graphics java
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Java wrapper for the cairo graphics package

LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo \
		libglibjni-${GLIB_API_VERSION}.so:${PORTSDIR}/devel/glib-java

OPTIONS_DEFINE=	docs

USES=		gmake pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_JAVA=	yes
JAVA_OS=	native
CONFIGURE_ARGS=	--without-gcj-compile --with-jardir=${JAVAJARDIR}
CPPFLAGS+=	-I${JAVA_HOME}/include -I${JAVA_HOME}/include/freebsd
CAIRO_API_VERSION=	1.0
GLIB_API_VERSION=	0.4
PLIST_SUB=		CAIRO_API_VERSION=${CAIRO_API_VERSION} PORTNAME=${PORTNAME}
SUB_FILES=	pkg-message
SUB_LIST=	JAVAJARDIR=${JAVAJARDIR} CAIRO_API_VERSION=${CAIRO_API_VERSION}

# jikes related
CONFIGURE_ENV+=	BOOTCLASSPATH=${JAVA_CLASSES}
MAKE_ENV+=	BOOTCLASSPATH=${JAVA_CLASSES}

.include <bsd.port.pre.mk>

.if ${JAVA_PORT_VERSION} == 1.6.0
PLIST_SUB+=	JDK16="" NOTJDK16="@comment "
.else
PLIST_SUB+=	JDK16="@comment " NOTJDK16=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
		${WRKSRC}/configure

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/.libs/libcairojni-${CAIRO_API_VERSION}.so \
		${STAGEDIR}${PREFIX}/lib/libcairojni-${CAIRO_API_VERSION}.so.1
	${LN} -sf libcairojni-${CAIRO_API_VERSION}.so.1 \
		${STAGEDIR}${PREFIX}/lib/libcairojni-${CAIRO_API_VERSION}.so
	@${MKDIR} ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/cairo-java.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/cairo${CAIRO_API_VERSION}.jar ${STAGEDIR}${JAVAJARDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/api
	cd ${WRKSRC}/doc/api && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/api
	${TOUCH} ${STAGEDIR}${DOCSDIR}/api/packages.html

.include <bsd.port.post.mk>
