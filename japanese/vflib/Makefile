# New ports collection makefile for:	vflib + FreeType
# Version required:	2.24 Patchlevel 1
# Date created:		10 May 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id: Makefile,v 1.18 1998/12/12 21:03:35 jseger Exp $
#

DISTNAME=	VFlib2-2.24.1
PKGNAME=	ja-vflib-2.24.1
CATEGORIES=	japanese print
MASTER_SITES=	ftp://gull.se.hiroshima-u.ac.jp/pub/TypeHack/ \
		ftp://gull.se.hiroshima-u.ac.jp/pub/VFlib/
DISTFILES=	VFlib2-2.24.1.tar.gz watanabe-vf.tar.Z

MAINTAINER=	mita@jp.FreeBSD.org

BUILD_DEPENDS=	libtool:${PORTSDIR}/devel/libtool
LIB_DEPENDS=	ttf.3:${PORTSDIR}/print/freetype

VFLIB_VERSION=	2.24.1
PLIST_SUB=	VFLIB_VERSION=${VFLIB_VERSION}

GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes

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
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
