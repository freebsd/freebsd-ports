# New ports collection makefile for:	mp3unicode
# Date created:		2007-09-29
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	mp3unicode
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	ID3 tags charset converter

LIB_DEPENDS=	tag.1:${PORTSDIR}/audio/taglib/

USE_BZIP2=	yes
USE_ICONV=	yes
USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ICONV_CFLAGS="-I${LOCALBASE}/include" \
		ICONV_LIBS="-L${LOCALBASE}/lib -liconv"

MAN1=		mp3unicode.1
PLIST_FILES=	bin/mp3unicode
PORTDOCS=	COPYING README

.include <bsd.port.pre.mk>

pre-configure:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '/^install-data-am/s|install-dist_docDATA||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
