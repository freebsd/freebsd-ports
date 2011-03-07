# New ports collection makefile for:   gbe
# Date created:        16 April 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gbe
PORTVERSION=	0.0.22
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	http://www.zophar.net/unix/Files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nintendo GameBoy(tm) emulator with GNU source code

PLIST_FILES=	bin/gbe

WRKSRC=		${WRKDIR}/${PORTNAME}
CPPFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

USE_XORG=	x11

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gbe ${PREFIX}/bin

.include <bsd.port.mk>
