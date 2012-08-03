# New ports collection makefile for:	dvi2tty
# Date created:			30 Mar. 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dvi2tty
PORTVERSION=	5.0
CATEGORIES=	japanese print
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	hrs
PKGNAMESUFFIX=	-ascii
DISTNAME=	dvi2tty${PORTVERSION}

PATCH_SITES=	${MASTER_SITES}
PATCH_SITE_SUBDIR=	${MASTER_SITE_SUBDIR}
PATCH_DIST_STRIP=	-p1
PATCHFILES=	dvi2tty-ascii-jtex-patch dvi2tty.c-patch

MAINTAINER=	turutani@scphys.kyoto-u.ac.jp
COMMENT=	Character-based DVI file previewer

RUN_DEPENDS=	jless:${PORTSDIR}/japanese/less

CONFLICTS=	dvi2tty-[0-9]*

PLIST_FILES=	bin/jdvi2tty bin/dvi2tty bin/disdvi

MAN1=		dvi2tty.1
MLINKS=		dvi2tty.1 jdvi2tty.1

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} jdvi2tty disdvi ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dvi2tty.1 ${PREFIX}/man/man1
	${LN} -sf ${PREFIX}/bin/jdvi2tty ${PREFIX}/bin/dvi2tty

.include <bsd.port.mk>
