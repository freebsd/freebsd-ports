# New ports collection makefile for: ja-rxvt
# Version required:	2.4.7
# Date created:         6 Oct 1998
# Whom:                 HONDA Yasuhiro <honda@kashio.info.mie-u.ac.jp>
#
#

FILESDIR=	${.CURDIR}/../../x11/rxvt/files
PATCHDIR=	${.CURDIR}/../../x11/rxvt/patches
PKGDIR=		${.CURDIR}/../../x11/rxvt/pkg

PKGNAME=	ja-rxvt-2.4.7

.include <${.CURDIR}/../../x11/rxvt/Makefile>

CATEGORIES=	japanese x11

MAINTAINER=	honda@kashio.info.mie-u.ac.jp

USE_X_PREFIX=	yes
HAS_CONFIGURE=  yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --enable-menubar --enable-kanji --with-x
