# ex:ts=8
# New ports collection makefile for:  mdk
# Date created:			Apr 1, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mdk
PORTVERSION=	1.2.1
PORTREVISION=	11
CATEGORIES=	lang gnome
MASTER_SITES=	${MASTER_SITE_GNU:S/%SUBDIR%/${PORTNAME}\/v${PORTVERSION}/} \
		SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of utilities for developing programs using MIX and MIXAL

LIB_DEPENDS=	guile.21:${PORTSDIR}/lang/guile \
		readline.6:${PORTSDIR}/devel/readline

USE_GNOME=	libglade2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		mdk

post-patch:
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
