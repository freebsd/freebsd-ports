# New ports collection makefile for:	mudmagic
# Date created:		2006-09-21
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	mudmagic
PORTVERSION=	1.9
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://www.mudmagic.com/mud-client/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK+ based MUD client

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		pcre.1:${PORTSDIR}/devel/pcre \
		png.6:${PORTSDIR}/graphics/png \
		expat:${PORTSDIR}/textproc/expat2 \
		sqlite3.8:${PORTSDIR}/databases/sqlite3

USE_GNOME=	gtk20 libglade2 libxml2 gnomehack
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		mudmagic.1

.include <bsd.port.mk>
