# Created by: Jeremy Norris <ishmael27@home.com>
# $FreeBSD$

PORTNAME=	scrot
PORTVERSION=	0.8
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://linuxbrit.co.uk/downloads/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A screen capture utility that utilizes Imlib2

LIB_DEPENDS=	giblib:${PORTSDIR}/graphics/giblib

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		scrot.1

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
MAKE_ENV=	NO_DOC=yes
.endif

.include <bsd.port.mk>
