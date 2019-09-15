# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	hffzip
PORTVERSION=	1.01
CATEGORIES=	archivers
MASTER_SITES=	http://retis.sssup.it/~scordino/code/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File compressor based on Huffman coding

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BROKEN=		unfetchable
DEPRECATED=	Unfetchable, unmaintained
EXPIRATION_DATE=	2019-10-16

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/hffzip

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin

.include <bsd.port.mk>
