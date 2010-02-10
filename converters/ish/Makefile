# New ports collection makefile for:	ish
# Date created:		13 August 1997
# Whom:			hosokawa
#
# $FreeBSD$

PORTNAME=	ish
PORTVERSION=	2.01a5
CATEGORIES=	converters
MASTER_SITES=	http://www.unix.gr.jp/jnetcex/soft/\
		${MASTER_SITE_PORTS_JP}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Binary-to-text file-encoder

MAKEFILE=	makefile
MAKE_ARGS=	CFLAGS="${CFLAGS}" DEST=${PREFIX}/bin
PLIST_FILES=	bin/ish
ALL_TARGET=	ish

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
