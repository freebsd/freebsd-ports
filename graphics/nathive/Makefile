# New ports collection makefile for:	nathive
# Date created:		24 Nov 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nathive
PORTVERSION=	0.811
CATEGORIES=	graphics
MASTER_SITES=	http://www.nathive.org/packages/ \
		http://www.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}_${PORTVERSION}_source

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Lightweight image editor

USE_GNOME=	pkgconfig glib20 gtk20
NO_WRKSUBDIR=	yes

post-patch:
	@${REINPLACE_CMD} -e '/define.*PATH/ s|".*"|"${DATADIR}/"|' \
		${WRKSRC}/nathive.c

do-build:
	cd ${WRKSRC} && \
		${CC} ${CFLAGS} `pkg-config --cflags --libs glib-2.0` \
		`pkg-config --cflags --libs gtk+-2.0` nathive.c -o nathive

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nathive ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} "cfg img lang palettes text" ${DATADIR}

.include <bsd.port.mk>
