# New ports collection makefile for:	mp3val
# Date created:		2010-04-19
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
#
# $FreeBSD$
#

PORTNAME=		mp3val
PORTVERSION=		0.1.8
CATEGORIES=		audio
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
DISTNAME=		${PORTNAME}-${PORTVERSION}-src

MAINTAINER=		sunpoet@sunpoet.net
COMMENT=		A program for MPEG audio stream validation

ALL_TARGET=		mp3val
MAKEFILE=		${WRKSRC}/Makefile.linux
PLIST_FILES=			bin/mp3val
USE_GMAKE=		yes

.include <bsd.port.pre.mk>

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mp3val ${PREFIX}/bin

.include <bsd.port.post.mk>
