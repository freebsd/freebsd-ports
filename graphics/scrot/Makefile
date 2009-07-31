# New ports collection makefile for:	scrot
# Date created:				27 Oct 2000
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	scrot
PORTVERSION=	0.8
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://linuxbrit.co.uk/downloads/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A screen capture utility that utilizes Imlib2

LIB_DEPENDS=	giblib.1:${PORTSDIR}/graphics/giblib

GNU_CONFIGURE=	yes

.if defined(NOPORTDOCS)
MAKE_ENV=	NO_DOC=yes
.endif

MAN1=		scrot.1

.include <bsd.port.mk>
