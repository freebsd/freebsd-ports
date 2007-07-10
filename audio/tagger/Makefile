# New ports collection makefile for:	tagger
# Date created:		2007-07-07
# Whom:			David Thiel <lx@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tagger
PORTVERSION=	0.2.7
CATEGORIES=	audio
MASTER_SITES=	http://onion.dynserv.net/~timo/files/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	CLI Ogg/Vorbis and MP3 ID3v1/ID3v1.1 tag editor

USE_BZIP2=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=prefix=${PREFIX} mandir=${MANPREFIX}/man
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
	LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/tagger

.include <bsd.port.mk>
