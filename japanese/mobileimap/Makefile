# New ports collection makefile for:	mobileimap
# Date created:				2004/05/09
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mobileimap
PORTVERSION=	2.7
CATEGORIES=	japanese mail
MASTER_SITES=	http://namazu.org/~satoru/mobileimap/

MAINTAINER=	nork@FreeBSD.org
COMMENT=	An IMAP-based webmail system for mobile-phones

USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv openssl zlib

RUBY_VER=	1.8
RUBY_SHEBANG_FILES=	mobileimap.in

ALL_TARGET=	mobileimap

PLIST_FILES=	bin/mobileimap

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
