# New ports collection makefile for:	d2x
# Date created:		5 Apr 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	d2x
PORTVERSION=	0.2.5
CATEGORIES=	games
MASTER_SITES=	http://www.icculus.org/d2x/src/

MAINTAINER=	hsn@netmag.cz
COMMENT=	Unix port of Descent 2 Game

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_SDL=	sdl image
USE_GMAKE=	yes

CONFIGURE_ARGS=	--disable-network --disable-debug

PORTDOCS=	README TODO NEWS AUTHORS readme.txt installation.txt
PLIST_FILES=	bin/d2x

do-install:
		${INSTALL} ${WRKSRC}/d2x-sdl ${PREFIX}/bin/d2x
.if !defined(NOPORTDOCS)
	        ${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	        ${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	        ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
