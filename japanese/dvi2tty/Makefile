# New ports collection makefile for:	dvi2tty
# Version required:		5.0
# Date created:			30 Mar. 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.7 1996/11/11 10:11:49 max Exp $
#

DISTNAME=	dvi2tty5.0
PKGNAME=	jp-dvi2tty-ascii-5.0
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ipc.chiba-u.ac.jp/misc/tex/dviwares/dvi2tty/ \
		ftp://ftp.web.ad.jp/pub/TeX/akiu/dviwares/dvi2tty/

PATCH_SITES=	ftp://ftp.ipc.chiba-u.ac.jp/misc/tex/dviwares/dvi2tty/ \
		ftp://ftp.web.ad.jp/pub/TeX/akiu/dviwares/dvi2tty/
PATCHFILES=	dvi2tty-ascii-jtex-patch dvi2tty.c-patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	max@FreeBSD.ORG

RUN_DEPENDS=	jless:${PORTSDIR}/japanese/less

MAN1=		dvi2tty.1

do-install:
	(for f in jdvi2tty disdvi ; do \
	${INSTALL_PROGRAM} ${WRKSRC}/$$f ${PREFIX}/bin ; done)
	${INSTALL_MAN} ${WRKSRC}/dvi2tty.1 ${PREFIX}/man/man1
	-ln -sf ${PREFIX}/bin/jdvi2tty ${PREFIX}/bin/dvi2tty
.if !defined(NOMANCOMPRESS)
	ln -sf ${PREFIX}/man/man1/dvi2tty.1.gz ${PREFIX}/man/man1/jdvi2tty.1.gz
.else
	ln -sf ${PREFIX}/man/man1/dvi2tty.1 ${PREFIX}/man/man1/jdvi2tty.1
.endif

.include <bsd.port.mk>
