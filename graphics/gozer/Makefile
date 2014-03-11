# Created by: Jeremy Norris <ishmael27@home.com>
# $FreeBSD$

PORTNAME=	gozer
PORTVERSION=	0.7
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://linuxbrit.co.uk/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Commandline text rendering utility - creates images from text

LIB_DEPENDS=	giblib.1:${PORTSDIR}/graphics/giblib

DEPRECATED=	Unmaintained since 2002
EXPIRATION_DATE=	2014-04-17
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-giblib-prefix=${LOCALBASE}

MAN1=		gozer.1

.if defined(NOPORTDOCS)
MAKE_ENV=	NO_DOC=yes
.endif

NO_STAGE=	yes
.include <bsd.port.mk>
