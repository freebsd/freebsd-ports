# New ports collection makefile for:	jp-vflib
# Version required:	2.22
# Date created:		10 May 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id$
#

DISTNAME=	VFlib-2.22
PKGNAME=	jp-vflib-2.22
CATEGORIES+=	japanese print
MASTER_SITES=	ftp://gull.se.hiroshima-u.ac.jp/pub/VFlib/
DISTFILES=	VFlib-2.22.tar.gz watanabe-vf.tar.Z

MAINTAINER=	mita@jp.FreeBSD.org

EXTRACT_ONLY=	VFlib-2.22.tar.gz

do-build:
	@(cd ${WRKSRC}/src; make)
	@(cd ${WRKSRC}/tools; xmkmf; make)

do-install:
	${MKDIR} /usr/local/lib/VFlib
	@(cd ${WRKSRC}/src; make install)
	@(cd ${WRKSRC}/tools; \
	  ${INSTALL_PROGRAM} fmtest disol kban ktest vfperf vftest \
	    /usr/local/lib/VFlib)
	@(cd ${WRKSRC}; \
	  cp -R doc jTeX COPYING README.txt.JP_EUC vfontcap \
	    /usr/local/lib/VFlib)
	${MKDIR} /usr/local/share/fonts/watanabe_font
	tar -C /usr/local/share/fonts/watanabe_font \
	  -xvzf ${DISTDIR}/watanabe-vf.tar.Z

.include <bsd.port.mk>
