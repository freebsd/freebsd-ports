# New ports collection makefile for:	dvi2tty
# Version required:		5.0
# Date created:			30 Mar. 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	dvi2tty5.0
PKGNAME=	ja-dvi2tty-ascii-5.0
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.web.ad.jp/pub/TeX/akiu/dviwares/dvi2tty/

PATCH_SITES=	ftp://ftp.web.ad.jp/pub/TeX/akiu/dviwares/dvi2tty/
PATCHFILES=	dvi2tty-ascii-jtex-patch dvi2tty.c-patch

MAINTAINER=	max@FreeBSD.org

RUN_DEPENDS=	jless:${PORTSDIR}/japanese/less

PATCH_DIST_STRIP=	-p1
MAN1=		dvi2tty.1
MLINKS=		dvi2tty.1 jdvi2tty.1

do-install:
	(for f in jdvi2tty disdvi ; do \
	${INSTALL_PROGRAM} ${WRKSRC}/$$f ${PREFIX}/bin ; done)
	${INSTALL_MAN} ${WRKSRC}/dvi2tty.1 ${PREFIX}/man/man1
	-${LN} -sf ${PREFIX}/bin/jdvi2tty ${PREFIX}/bin/dvi2tty

.include <bsd.port.mk>
