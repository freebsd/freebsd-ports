# New ports collection makefile for:	dvi2tty
# Date created:			30 Mar. 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dvi2tty-ascii
PORTVERSION=	5.0
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.web.ad.jp/pub/TeX/akiu/dviwares/dvi2tty/
DISTNAME=	dvi2tty${PORTVERSION}

PATCH_SITES=	ftp://ftp.web.ad.jp/pub/TeX/akiu/dviwares/dvi2tty/
PATCHFILES=	${PORTNAME}-jtex-patch \
		dvi2tty.c-patch

MAINTAINER=	max@FreeBSD.org
COMMENT=	Character-based DVI file previewer

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
