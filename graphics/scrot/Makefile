# Created by: Jeremy Norris <ishmael27@home.com>
# $FreeBSD$

PORTNAME=	scrot
PORTVERSION=	0.8
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://linuxbrit.co.uk/downloads/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Screen capture utility that utilizes Imlib2

LIB_DEPENDS=	libgiblib.so:graphics/giblib

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
