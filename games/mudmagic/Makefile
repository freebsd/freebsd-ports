# New ports collection makefile for:	mudmagic
# Date created:		2006-09-21
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	mudmagic
PORTVERSION=	1.9
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://www.mudmagic.com/mud-client/downloads/

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	A GTK+ based MUD client

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl \
		pcre.0:${PORTSDIR}/devel/pcre \
		png.5:${PORTSDIR}/graphics/png \
		expat:${PORTSDIR}/textproc/expat2 \
		sqlite3.8:${PORTSDIR}/databases/sqlite3

USE_GNOME=	gtk20 libglade2 libxml2 gnomehack
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PYTHON=	24
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		mudmagic.1

.include <bsd.port.mk>
