# New ports collection makefile for:	vflib + FreeType
# Version required:	2.24 Patchlevel 2
# Date created:		10 May 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	VFlib2-2.24.2
PKGNAME=	ja-vflib-2.24.2
CATEGORIES=	japanese print
MASTER_SITES=	ftp://gull.se.hiroshima-u.ac.jp/pub/TypeHack/
DISTFILES=	VFlib2-2.24.2.tar.gz watanabe-vf.tar.Z

MAINTAINER=	mita@jp.FreeBSD.org

LIB_DEPENDS=	ttf.4:${PORTSDIR}/print/freetype

VFLIB_VERSION=	2.24.2
PLIST_SUB=	VFLIB_VERSION=${VFLIB_VERSION}

GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS=	--with-freetype \
		--with-freetype-includedir=${PREFIX}/include \
		--with-freetype-libdir=${PREFIX}/lib

pre-install:
	@(cd ${WRKSRC}/tools; \
	    ${INSTALL_SCRIPT} fmtest disol kban vfperf vftest ${PREFIX}/bin)
	@(cd ${WRKSRC}; \
	  ${MKDIR} ${PREFIX}/share/VFlib/${VFLIB_VERSION} ;\
	  ${CP} COPYING COPYING.LIB README.txt.JP_EUC \
		${PREFIX}/share/VFlib/${VFLIB_VERSION} ;\
	  ${CP} -R jTeX ${PREFIX}/share/VFlib/${VFLIB_VERSION})
	${MKDIR} ${PREFIX}/share/fonts/watanabe_font
	tar -C ${PREFIX}/share/fonts/watanabe_font \
	  -xzf ${DISTDIR}/watanabe-vf.tar.Z

post-install:
	${MV} ${PREFIX}/share/VFlib/${VFLIB_VERSION}/VF.h ${PREFIX}/include

.include <bsd.port.mk>
