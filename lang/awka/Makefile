# ex:ts=8
# New ports collection makefile for:	awka
# Date created:			May 31, 2001
# Whom:				ijliao
#
# $FreeBSD$

PORTNAME=	awka
PORTVERSION=	0.7.5
CATEGORIES=	lang
MASTER_SITES=	http://awka.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts the AWK script to C, then compiles it

GNU_CONFIGURE=	yes

INSTALLS_SHLIB=	yes

MANCOMPRESSED=	no
MAN1=	awka.1
MAN5=	awka-elm.5 awka-elmref.5

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/awka

.include <bsd.port.mk>
