# New ports collection makefile for:	vflib
# Version required:	2.22 Patchlevel 10
# Date created:		10 May 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id: Makefile,v 1.10 1997/10/02 03:10:04 max Exp $
#

DISTNAME=	VFlib-2.22-PL8
PKGNAME=	ja-vflib-2.22.10
CATEGORIES=	japanese print
MASTER_SITES=	ftp://gull.se.hiroshima-u.ac.jp/pub/VFlib/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} watanabe-vf.tar.Z

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	VFlib-2.22-Patch9 VFlib-2.22-Patch10

MAINTAINER=	mita@jp.FreeBSD.org

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}/VFlib-2.22pl8
PATCH_DIST_ARGS=-d ${WRKSRC}/src --forward --quiet -E ${PATCH_STRIP}

do-build:
	@(cd ${WRKSRC}/src; make)
	@(cd ${WRKSRC}/tools; xmkmf; make)

do-install:
	${MKDIR} ${PREFIX}/lib/VFlib
	@(cd ${WRKSRC}/src; make install)
	@(cd ${WRKSRC}/tools; \
	  ${INSTALL_PROGRAM} fmtest disol kban ktest vfperf vftest \
	    ${PREFIX}/lib/VFlib)
	@(cd ${WRKSRC}; \
	  ${CP} -R doc jTeX COPYING README.txt.JP_EUC vfontcap \
	    vfontcap.bdf vfontcap.comp2 ${PREFIX}/lib/VFlib)
	${MKDIR} ${PREFIX}/share/fonts/watanabe_font
	tar -C ${PREFIX}/share/fonts/watanabe_font \
	  -xzf ${DISTDIR}/watanabe-vf.tar.Z
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
