# ex:ts=8
# New ports collection makefile for:	awka
# Date created:			May 31, 2001
# Whom:				ijliao
#
# $FreeBSD$

PORTNAME=	awka
PORTVERSION=	0.7.4
CATEGORIES=	lang
MASTER_SITES=	http://awka.sourceforge.net/

MAINTAINER=	ijliao@FreeBSD.org

GNU_CONFIGURE=	yes

INSTALLS_SHLIB=	yes

MANCOMPRESSED=	no
MAN1=	awka.1
MAN5=	awka-elm.5 awka-elmref.5

post-install:
	@strip ${PREFIX}/bin/awka

.include <bsd.port.mk>
