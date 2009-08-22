# New ports collection makefile for:	goom
# Date created:				12 February 2005
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	goom
PORTVERSION=	2k4.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}2k4/0
DISTNAME=	${PORTNAME}-${PORTVERSION:S|.|-|}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visual effects library

USE_AUTOTOOLS=	libtool:22
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:S|.|-|}
USE_GNOME=	gnomehack gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-sdltest --enable-static
USE_LDCONFIG=	yes

.if exists(${X11R6}/bin/xmms) || defined(WITH_XMMS)
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
PLIST_SUB+=	XMMS=""
.else
PLIST_SUB+=	XMMS="@comment "
.endif

pre-everything::
.if !defined(WITH_XMMS)
	@${ECHO} ""
	@${ECHO} "Define WITH_XMMS to build goom xmms visualization plugin"
	@${ECHO} ""
.endif

.include <bsd.port.mk>
