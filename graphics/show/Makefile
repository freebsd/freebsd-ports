# New ports collection makefile for:	show
# Date created:        06 July 2003
# Whom:                roop
#
# $FreeBSD$
#

PORTNAME=	show
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.ugrad.cs.ubc.ca/~i6a2/show/

MAINTAINER=	i6a2@ugrad.cs.ubc.ca
COMMENT=	A fast, flexible, extensible and bloat-free image viewer for X11

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg	\
		png.5:${PORTSDIR}/graphics/png		\
		tiff.4:${PORTSDIR}/graphics/tiff	\
		ungif.5:${PORTSDIR}/graphics/libungif	\
		Imlib.5:${PORTSDIR}/graphics/imlib

USE_XLIB=	yes
USE_X_PREFIX=	yes

do-install:
		@${INSTALL_PROGRAM} ${WRKSRC}/show ${PREFIX}/bin

.include <bsd.port.mk>
