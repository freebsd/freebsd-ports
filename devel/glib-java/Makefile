# New ports collection makefile for:   glib-java
# Date created:        26 Oct 2005
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/glib-java/Makefile,v 1.2 2005/10/29 22:06:05 marcus Exp $
#

PORTNAME=	glib-java
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Java wrapper GLib 2

USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.2+
JAVA_OS=	native
USE_GCC=	3.4+
USE_GNOME=	gnomehack glib20
CONFIGURE_ARGS=	--without-gcj-compile
CONFIGURE_ENV=	CPPFLAGS="-I${JAVA_HOME}/include -I${JAVA_HOME}/include/freebsd"
GLIB_API_VERSION=	0.2
PLIST_SUB=		GLIB_API_VERSION=${GLIB_API_VERSION} PORTNAME=${PORTNAME}
PKGMESSAGE=		${WRKDIR}/pkg-message

# Jikes related
ONFIGURE_ENV+=	BOOTCLASSPATH=${JAVA_CLASSES}
MAKE_ENV+=	BOOTCLASSPATH=${JAVA_CLASSES}

do-install:
	${MKDIR} ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/.libs/libglibjni-${GLIB_API_VERSION}.so \
		${PREFIX}/lib/libglibjni-${GLIB_API_VERSION}.so.1
	${LN} -sf ${PREFIX}/lib/libglibjni-${GLIB_API_VERSION}.so.1 \
		${PREFIX}/lib/libglibjni-${GLIB_API_VERSION}.so
	${MKDIR} ${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/glib-java.pc ${PREFIX}/libdata/pkgconfig
	${MKDIR} ${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/jni/jg_jnu.h ${PREFIX}/include/${PORTNAME}
	${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/glib${GLIB_API_VERSION}.jar ${JAVAJARDIR}
	${MKDIR} ${PREFIX}/share/${PORTNAME}/macros
	${INSTALL_DATA} ${WRKSRC}/macros/* ${PREFIX}/share/${PORTNAME}/macros

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
	${TOUCH} ${DOCSDIR}/api/serialized-form.html
.endif
	@${SED} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|g ; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%GLIB_API_VERSION%%|${GLIB_API_VERSION}|g' \
		 < ${PKGDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
