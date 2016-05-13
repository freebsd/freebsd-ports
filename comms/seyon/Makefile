# Created by: Michael Elbel (me)
# $FreeBSD$

PORTNAME=	seyon
PORTVERSION=	2.20c
CATEGORIES=	comms
MASTER_SITES=	DEBIAN
DISTFILES=	${DISTNAME:S/-/_/}.orig${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Communications package for the X Window system

USES=		imake
USE_XORG=	x11 xext xpm xmu xaw xt sm ice

PLIST_FILES=	bin/seyon lib/X11/app-defaults/Seyon \
		lib/X11/app-defaults/Seyon-color lib/X11/seyon.help \
		man/man1/${PORTNAME}.1.gz

post-extract:
	${CHMOD} +x ${WRKSRC}/makever.sh

post-patch:
	${REINPLACE_CMD} -e "s/getline(/seyon_getline(/g" \
		${WRKSRC}/SeDecl.h ${WRKSRC}/SeScript.c ${WRKSRC}/SeSupp.c

.include <bsd.port.mk>
