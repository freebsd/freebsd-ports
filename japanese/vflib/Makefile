# New ports collection makefile for:	jp-vflib
# Version required:	2.22
# Date created:		10 May 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id: Makefile,v 1.1.1.1 1996/11/02 12:09:35 asami Exp $
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
	${MKDIR} ${PREFIX}/lib/VFlib
	@(cd ${WRKSRC}/src; make install)
	@(cd ${WRKSRC}/tools; \
	  ${INSTALL_PROGRAM} fmtest disol kban ktest vfperf vftest \
	    ${PREFIX}/lib/VFlib)
	@(cd ${WRKSRC}; \
	  ${CP} -R doc jTeX COPYING README.txt.JP_EUC vfontcap \
	    ${PREFIX}/lib/VFlib)
	${MKDIR} ${PREFIX}/share/fonts/watanabe_font
	tar -C ${PREFIX}/share/fonts/watanabe_font \
	  -xzf ${DISTDIR}/watanabe-vf.tar.Z

.include <bsd.port.mk>
