# New ports collection makefile for:   gbe
# Date created:        16 April 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gbe
PORTVERSION=	0.0.22
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.zophar.net/unix/Files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nintendo GameBoy(tm) emulator with GNU source code

PLIST_FILES=	bin/gbe
USE_GETOPT_LONG=yes

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ENV=	CPPFLAGS="${CPPFLAGS} -I${X11BASE}/include" \
		LDFLAGS="${LDFLAGS} -L${X11BASE}/lib"

USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gbe ${PREFIX}/bin

.include <bsd.port.mk>
