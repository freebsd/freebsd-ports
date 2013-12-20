# Created by: hosokawa
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
ALL_TARGET=	ish

PLIST_FILES=	bin/ish

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ish ${STAGEDIR}${PREFIX}/bin)

.include <bsd.port.mk>
