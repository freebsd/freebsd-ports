# New ports collection makefile for:	znibbles
# Date created:		21 Aug 1999
# Whom:			Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	znibbles
PORTVERSION=	0.0.7
CATEGORIES=	games
MASTER_SITES=	ftp://koala.inria.fr/pub/games/znibbles/

MAINTAINER=	yinjieh@csie.nctu.edu.tw

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

REQUIRES_MOTIF=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}"
CONFIGURE_ARGS=	--without-motif \
		--disable-motif

MAN6=	nibbles.6 znibbles.6 gznibbles.6 znibblesX.6

post-install:
	@strip ${PREFIX}/bin/nibbles
	@strip ${PREFIX}/bin/znibblesX
	@strip ${PREFIX}/bin/gznibbles

.include <bsd.port.mk>
