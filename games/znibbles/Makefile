# New ports collection makefile for:	znibbles
# Date created:		21 Aug 1999
# Whom:			Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	znibbles
PORTVERSION=	0.0.7
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://koala.ilog.fr/ftp/pub/games/znibbles/

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	A multi-player networked nibbles game

USE_MOTIF=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-motif \
		--disable-motif

MAN6=	nibbles.6 znibbles.6 gznibbles.6 znibblesX.6

.include <bsd.port.mk>
