# New ports collection makefile for:	vflib + FreeType
# Date created:		10 May 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vflib
PORTVERSION=	${VFLIB_VERSION}
CATEGORIES=	japanese print
MASTER_SITES=	ftp://gull.se.hiroshima-u.ac.jp/pub/TypeHack/
DISTNAME=	VFlib2-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	mita@FreeBSD.org

BUILD_DEPENDS=	xmkmf:${PORTSDIR}/devel/imake-4
RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/TrueType/kochi-mincho.ttf:${PORTSDIR}/japanese/kochi-ttfonts

VFLIB_VERSION=	2.25.6
PLIST_SUB=	VFLIB_VERSION=${VFLIB_VERSION}

USE_FREETYPE=	yes
USE_XLIB=	yes
USE_AUTOCONF_VER=213
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-freetype \
		--with-freetype-includedir=${PREFIX}/include/freetype \
		--with-freetype-libdir=${PREFIX}/lib

pre-install:
	@(cd ${WRKSRC}/tools; \
	    ${INSTALL_SCRIPT} fmtest disol kban vfperf vftest ${PREFIX}/bin)
	@(cd ${WRKSRC}; \
	  ${MKDIR} ${PREFIX}/share/VFlib/${VFLIB_VERSION} ;\
	  ${CP} COPYING COPYING.LIB README.txt.JP_EUC \
		${PREFIX}/share/VFlib/${VFLIB_VERSION} ;\
	  ${CP} -R jTeX ${PREFIX}/share/VFlib/${VFLIB_VERSION})

post-install:
	${MV} ${PREFIX}/share/VFlib/${VFLIB_VERSION}/VF.h ${PREFIX}/include

.include <bsd.port.mk>
