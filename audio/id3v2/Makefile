# New ports collection makefile for:	id3v2
# Date created:		10 Oct 2001
# Whom:			David MacKenzie <djm@pix.net>
#
# $FreeBSD$
#

PORTNAME=	id3v2
PORTVERSION=	0.1.9
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	id3v2

MAINTAINER=	rehsack@liwing.de
COMMENT=	Command line id3v2 tag editor

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib

USE_GETOPT_LONG=yes
CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT=1
LDFLAGS=	-L${LOCALBASE}/lib
CFLAGS+=	${CPPFLAGS}
MAKE_ENV=	LDFLAGS="${LDFLAGS}"

MAN1=		id3v2.1
PLIST_FILES=	bin/id3v2

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/id3v2 ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/id3v2.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
