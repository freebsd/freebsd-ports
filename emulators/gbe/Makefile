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
MASTER_SITES=	http://www.zophar.net/fileuploads/1/468dreaj/ \
		ftp://ftp.canadatux.org/videogames/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nintendo GameBoy(tm) emulator with GNU source code

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XORG=	x11
MAKE_ENV=	LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/gbe

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gbe ${PREFIX}/bin

.include <bsd.port.mk>
