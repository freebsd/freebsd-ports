# Created by: mm
# $FreeBSD$

PORTNAME=	pxz
PORTVERSION=	0.20141018
PORTREVISION=	4
CATEGORIES=	archivers
MASTER_SITES=	LOCAL/delphij
DISTNAME=	pxz-git-${PORTVERSION:S/0.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parallel LZMA compressor using liblzma

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		compiler:openmp tar:xz
PLIST_FILES=	bin/pxz man/man1/pxz.1.gz

MAKE_ENV+=	BINDIR=${PREFIX}/bin \
		MANDIR=${MANPREFIX}/man

MAKE_ARGS+=	CC="${CC}"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pxz

.include <bsd.port.mk>
