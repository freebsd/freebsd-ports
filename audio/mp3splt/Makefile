# New ports collection makefile for:	audio/mp3splt
# Date created:				30.05.2003
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	mp3splt
PORTVERSION=	2.2.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	citrin@citrin.ru
COMMENT=	Utility to split mp3 and ogg files (via CUE sheets)

LIB_DEPENDS=	mp3splt:${PORTSDIR}/audio/libmp3splt

USE_AUTOTOOLS=	libltdl
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"

MAN1=		mp3splt.1
PLIST_FILES=	bin/mp3splt bin/oggsplt

post-install:
	@${LN} -fsv ${PREFIX}/bin/mp3splt ${PREFIX}/bin/oggsplt

.include <bsd.port.mk>
