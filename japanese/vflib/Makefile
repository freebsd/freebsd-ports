# New ports collection makefile for:	vflib
# Version required:	2.22 Patchlevel 9
# Date created:		10 May 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id: Makefile,v 1.8 1997/07/24 20:52:43 max Exp $
#

DISTNAME=	VFlib-2.22-PL8
PKGNAME=	ja-vflib-2.22.9
CATEGORIES=	japanese print
MASTER_SITES=	ftp://gull.se.hiroshima-u.ac.jp/pub/VFlib/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} VFlib-2.22-Patch9 watanabe-vf.tar.Z

MAINTAINER=	mita@jp.FreeBSD.org

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}/VFlib-2.22pl8

pre-patch:
	@(cd ${WRKSRC}/src; \
	  ${PATCH} --forward --quiet -p0 -E < ${DISTDIR}/VFlib-2.22-Patch9 )


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
