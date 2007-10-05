# New ports collection makefile for:	mp3unicode
# Date created:		2007-09-29
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	mp3unicode
PORTVERSION=	1.2
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	makc@issp.ac.ru
COMMENT=	ID3 tags charset converter

LIB_DEPENDS=	tag.5:${PORTSDIR}/audio/taglib/

USE_BZIP2=	yes
USE_ICONV=	yes
USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ICONV_CFLAGS="-I${LOCALBASE}/include" \
		ICONV_LIBS="-L${LOCALBASE}/lib -liconv"

MAN1=		mp3unicode.1
PLIST_FILES=	bin/mp3unicode
PORTDOCS=	COPYING README

.include <bsd.port.mk>
