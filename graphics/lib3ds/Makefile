# New ports collection makefile for:	lib3ds
# Date Created:				18 January 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lib3ds
PORTVERSION=	1.2.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for handling 3DS (3D Studio) files

USE_MESA=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib"

MAN1=		3ds2m.1 3dsdump.1 lib3ds-config.1

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/examples/3ds2rib ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/examples/player ${PREFIX}/bin/3dsplayer
	${INSTALL_PROGRAM} ${WRKSRC}/lib3ds/lib3ds.so.1 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/lib3ds.so.1 ${PREFIX}/lib/lib3ds.so

.include <bsd.port.mk>
