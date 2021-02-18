# $FreeBSD$

PORTNAME=	goredo
DISTVERSION=	1.3.0
CATEGORIES=	devel
MASTER_SITES=	http://www.goredo.cypherpunks.ru/download/
EXTRACT_SUFX=	.tar.zst

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Go implementation of djb's redo, Makefile replacement that sucks less

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

USES=		go

WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1200000
EXTRACT_DEPENDS=	zstd:archivers/zstd # 11 doesn't have the 'zstd' executable that tar(1) expects: Error opening archive: Can't initialize filter; unable to run program "zstd -d -qq"
.endif

.include <bsd.port.mk>
