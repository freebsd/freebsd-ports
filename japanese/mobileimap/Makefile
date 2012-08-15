# New ports collection makefile for:	mobileimap
# Date created:				2004/05/09
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mobileimap
PORTVERSION=	2.7
CATEGORIES=	japanese mail
MASTER_SITES=	http://0xcc.net/mobileimap/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An IMAP-based webmail system for mobile-phones

USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv openssl zlib

RUBY_SHEBANG_FILES=	mobileimap.in

ALL_TARGET=	mobileimap

PLIST_FILES=	bin/mobileimap

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/Makefile

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not build with ruby 1.9
.endif
.include <bsd.port.post.mk>
