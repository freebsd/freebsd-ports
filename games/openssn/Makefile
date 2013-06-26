# Created by: Jesse Smith <jessefrgsmith@yahoo.ca>
# $FreeBSD$

PORTNAME=	openssn
PORTVERSION=	1.4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	jessefrgsmith@yahoo.ca
COMMENT=	Modern submarine simulator

LICENSE=	GPLv2

MAN6=		openssn.6
MANCOMPRESSED=	yes

USES=		desktop-file-utils
USE_SDL=	sdl gfx image mixer
USE_XORG=	x11 xau xdmcp xext xmu xpm xxf86vm
WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's,share/man/man6,man/man6,g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
