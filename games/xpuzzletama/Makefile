# New ports collection makefile for:   xpuzzletama
# Version required:    1.5
# Date created:        18 January 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id$
#

DISTNAME=	xpuzzletama
PKGNAME=        xpuzzletama-1.5
CATEGORIES=     games x11
MASTER_SITES=   http://neo.yanagi.gifu-u.ac.jp/~c94056/
DISTFILES=	PuzzleTama-ver1.5.tar.gz

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

CONFIGURE_ENV=  X11BASE=${X11BASE}

LIB_DEPENDS=    Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=      yes
NO_INSTALL_MANPAGES=    yes

post-install:
	${MKDIR} ${PREFIX}/lib/X11/xpuzzletama
	${INSTALL} ${COPY} -o ${SHAREOWN} -g ${SHAREGRP} -m 666 \
		${WRKSRC}/.tama_score ${PREFIX}/lib/X11/xpuzzletama/tama_score

.include <bsd.port.mk>
