# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	joytran
PORTVERSION=	0.9.5.2
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://sourceforge.net/projects/${PORTNAME}/files/

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Joystick to keyboard/mouse events translator written in C

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USE_SDL=	sdl2
USES=		tar:bzip2 cmake:insource pkgconfig xorg
CMAKE_ARGS=	-DLOCALBASE="${LOCALBASE}" -DPREFIX="${PREFIX}"
USE_XORG=	x11 xtst

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
