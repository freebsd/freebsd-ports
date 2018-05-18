# Created by: Jeremy Norris <ishmael27@home.com>
# $FreeBSD$

PORTNAME=	scrot
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	0.8
PORTREVISION=	8
CATEGORIES=	graphics

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Screen capture utility that utilizes Imlib2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgiblib.so:graphics/giblib \
		libImlib2.so:graphics/imlib2

USE_GITHUB=	yes
GH_ACCOUNT=	dreamer

GNU_CONFIGURE=	yes
USE_XORG=	x11

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
