# New ports collection makefile for:	OpenSSN
# Date created:			30, May 2011
# Whom:				Jesse Smith <jessefrgsmith@yahoo.ca>
#
# $FreeBSD$
#

PORTNAME=	openssn
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	jessefrgsmith@yahoo.ca
COMMENT=	A modern submarine simulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_SDL=	sdl gfx image mixer
USE_XORG=	x11 xau xdmcp xext xmu xpm xxf86vm
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
