# Created by: Masafumi NAKANE <max@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dvi2tty
PORTVERSION=	5.0
PORTREVISION=	2
CATEGORIES=	japanese print
MASTER_SITES=	LOCAL/hrs
PKGNAMESUFFIX=	-ascii
DISTNAME=	dvi2tty${PORTVERSION}

PATCH_SITES=	${MASTER_SITES}
PATCH_DIST_STRIP=	-p1
PATCHFILES=	dvi2tty-ascii-jtex-patch dvi2tty.c-patch

MAINTAINER=	TsurutaniNaoki@gmail.com
COMMENT=	Character-based DVI file previewer

RUN_DEPENDS=	jless:japanese/less

PLIST_FILES=	bin/jdvi2tty \
		bin/jdisdvi \
		man/man1/jdvi2tty.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jdvi2tty ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/disdvi ${STAGEDIR}${PREFIX}/bin/jdisdvi
	${INSTALL_MAN} ${WRKSRC}/dvi2tty.1 ${STAGEDIR}${PREFIX}/man/man1/jdvi2tty.1

.include <bsd.port.mk>
