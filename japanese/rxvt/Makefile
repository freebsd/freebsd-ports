# New ports collection makefile for: ja-rxvt
# Version required:	2.4.5
# Date created:         12 Jun 1998
# Whom:                 HONDA Yasuhiro <honda@kashio.info.mie-u.ac.jp>
#
#

FILESDIR=	${.CURDIR}/../../x11/rxvt/files
PATCHDIR=	${.CURDIR}/../../x11/rxvt/patches
PKGDIR=		${.CURDIR}/../../x11/rxvt/pkg

PKGNAME=	ja-rxvt-2.4.5

.include <${.CURDIR}/../../x11/rxvt/Makefile>

CATEGORIES=	japanese x11

MAINTAINER=	honda@kashio.info.mie-u.ac.jp

USE_X11=	yes
HAS_CONFIGURE=  yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --enable-menubar --enable-kanji --with-x
