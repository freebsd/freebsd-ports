# New ports collection makefile for:	vflib + FreeType
# Version required:	2.22 Patchlevel 10
# Date created:		10 May 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id: Makefile,v 1.17 1998/10/04 14:47:13 kuriyama Exp $
#

DISTNAME=	VFlib-2.23-PL1
PKGNAME=	ja-vflib-2.23.1
CATEGORIES=	japanese print
MASTER_SITES=	ftp://gull.se.hiroshima-u.ac.jp/pub/TypeHack/
DISTFILES=	TypeHack-19980625.tar.gz watanabe-vf.tar.Z

MAINTAINER=	mita@jp.FreeBSD.org

BUILD_DEPENDS=	libtool:${PORTSDIR}/devel/libtool
LIB_DEPENDS=	ttf.3:${PORTSDIR}/print/freetype

EXTRACT_ONLY=	TypeHack-19980625.tar.gz
WRKSRC=		${WRKDIR}/TypeHack-19980625/VFlib2-2.23.1
GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes

post-install:
	@(cd ${WRKSRC}/tools; \
	    ${INSTALL_SCRIPT} fmtest disol kban vfperf vftest ${PREFIX}/bin)
	${MKDIR} ${PREFIX}/share/doc/VFlib2-2.23.1
	@(cd ${WRKSRC}; \
	  ${CP} -R doc COPYING COPYING.LIB README.txt.JP_EUC \
	    ${PREFIX}/share/doc/VFlib2-2.23.1)
	@(cd ${WRKSRC}; \
	  ${CP} -R jTeX ${PREFIX}/share/VFlib/2.23.1)
	${MKDIR} ${PREFIX}/share/fonts/watanabe_font
	tar -C ${PREFIX}/share/fonts/watanabe_font \
	  -xzf ${DISTDIR}/watanabe-vf.tar.Z
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
