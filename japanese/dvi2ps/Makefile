# New ports collection makefile for: jp-dvi2ps
# Version required:	2.0beta4
# Date created:		15 Sep 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id: Makefile,v 1.2 1996/11/11 10:11:47 max Exp $
#

DISTNAME=	dvi2ps-2.0j-beta4
PKGNAME=	jp-dvi2ps-2.0b4
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.math.s.chiba-u.ac.jp/tex/
DISTFILES=	dvi2ps-2.0j-beta4.tar.gz

MAINTAINER=	mita@jp.FreeBSD.org

LIB_DEPENDS=	VFlib\\.2\\.:${PORTSDIR}/japanese/vflib

post-patch:
	@(cd ${WRKSRC}; make newlib)

post-build:
	@(cd ${WRKSRC}/tools; \
	cc -O -o nup nup.c; \
	cc -O -traditional -o texfix texfix.c\
		)
post-install:
	@(cd  ${WRKSRC}; \
	make install-lib; \
	${CP} -R doc ${PREFIX}/lib/dvi2ps/ ;\
	${INSTALL_SCRIPT} tools/lnfonts ${PREFIX}/lib/dvi2ps ;\
	${INSTALL_PROGRAM} tools/nup ${PREFIX}/bin ;\
	${INSTALL_PROGRAM} tools/texfix ${PREFIX}/bin ;\
	${INSTALL_SCRIPT} tools/psstrip ${PREFIX}/bin ;\
	${INSTALL_SCRIPT} tools/MakePK ${PREFIX}/bin ;\
	)
	@/bin/sh ${PKGDIR}/REQ ${PKGNAME} INSTALL

.include <bsd.port.mk>
