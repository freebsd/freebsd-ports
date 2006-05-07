# New ports collection makefile for:   cairo-java
# Date created:        26 Oct 2005
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/cairo-java/Makefile,v 1.2 2005/10/29 22:06:06 marcus Exp $
#

PORTNAME=	cairo-java
PORTVERSION=	1.0.3
CATEGORIES=	graphics java
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.0
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Java wrapper for the cairo graphics package

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo \
		glibjni-${GLIB_API_VERSION}.1:${PORTSDIR}/devel/glib-java

USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.2+
JAVA_OS=	native
USE_GCC=	3.4+
USE_GNOME=	gnomehack gnometarget
CONFIGURE_ARGS=	--without-gcj-compile
CONFIGURE_ENV=	CPPFLAGS="-I${JAVA_HOME}/include -I${JAVA_HOME}/include/freebsd"
CAIRO_API_VERSION=	1.0
GLIB_API_VERSION=	0.2
PLIST_SUB=		CAIRO_API_VERSION=${CAIRO_API_VERSION} PORTNAME=${PORTNAME}
PKGMESSAGE=		${WRKDIR}/pkg-message

do-install:
	${MKDIR} ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/.libs/libcairojni-${CAIRO_API_VERSION}.so \
		${PREFIX}/lib/libcairojni-${CAIRO_API_VERSION}.so.1
	${LN} -sf ${PREFIX}/lib/libcairojni-${CAIRO_API_VERSION}.so.1 \
		${PREFIX}/lib/libcairojni-${CAIRO_API_VERSION}.so
	${MKDIR} ${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/cairo-java.pc ${PREFIX}/libdata/pkgconfig
	${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/cairo${CAIRO_API_VERSION}.jar ${JAVAJARDIR}

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
.endif
	@${SED} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|g ; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%CAIRO_API_VERSION%%|${CAIRO_API_VERSION}|g' \
		 < ${PKGDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
