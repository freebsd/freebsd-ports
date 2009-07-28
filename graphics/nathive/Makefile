# New ports collection makefile for:	nathive
# Date created:		24 Nov 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nathive
PORTVERSION=	0.813
CATEGORIES=	graphics
MASTER_SITES=	http://www.nathive.org/packages/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}_${PORTVERSION}_source

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Lightweight image editor

USE_GNOME=	pkgconfig glib20 gtk20
ALL_TARGET=	default

post-patch:
	@${REINPLACE_CMD} -e '/define.*PATH/ s|".*"|"${DATADIR}/"|' \
		${WRKSRC}/main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nathive ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} "cfg img lang palettes text" ${DATADIR}

.include <bsd.port.mk>
