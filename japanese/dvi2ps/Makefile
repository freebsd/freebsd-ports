# New ports collection makefile for: jp-dvi2ps
# Date created:		15 Sep 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dvi2ps
PORTVERSION=	3.2
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.math.s.chiba-u.ac.jp/tex/
DISTNAME=	${PORTNAME}-${PORTVERSION}j

MAINTAINER=	mita@FreeBSD.org

BUILD_DEPENDS=	${PREFIX}/lib/libkpathsea.a:${PORTSDIR}/japanese/ptex-common
LIB_DEPENDS=	VFlib2.24:${PORTSDIR}/japanese/vflib

MAN1=		dvi2ps.1 ../ja/man1/dvi2ps.1

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
	${INSTALL_DATA} ${WRKSRC}/man/dvi2ps.man ${PREFIX}/man/man1/dvi2ps.1 ;\
	${INSTALL_DATA} ${WRKSRC}/man/dvi2ps.jman \
			${PREFIX}/man/ja/man1/dvi2ps.1 ;\
	${RM} -f ${PREFIX}/lib/dvi2ps/doc/dvi2ps.jman ;\
	${INSTALL_SCRIPT} tools/fontlink ${PREFIX}/lib/dvi2ps ;\
	${INSTALL_PROGRAM} tools/nup ${PREFIX}/bin ;\
	${INSTALL_PROGRAM} tools/texfix ${PREFIX}/bin ;\
	${INSTALL_SCRIPT} tools/psstrip ${PREFIX}/bin ;\
	${INSTALL_SCRIPT} tools/MakePK ${PREFIX}/bin ;\
	)
	@${SH} ${PKGREQ} ${PKGNAME} INSTALL

.include <bsd.port.mk>
