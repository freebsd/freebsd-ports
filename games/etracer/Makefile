# Created by: Peter Dunning
# $FreeBSD$

PORTNAME=	etr
PORTVERSION=	0.7.5
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/extremetuxracer/releases/${PORTVERSION}
PKGNAMESUFFIX=	acer

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Extreme Tux Racer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsfml-system.so:devel/sfml

USES=		compiler:c++11-lang gl pkgconfig tar:xz xorg
USE_GL=		gl glu
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
