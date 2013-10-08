# Created by: mm
# $FreeBSD$

PORTNAME=	pxz
PORTVERSION=	0.20120930
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mm
DISTNAME=	pxz-git-${PORTVERSION:S/0.//}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Parallel LZMA compressor using liblzma

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
PLIST_FILES=	bin/pxz
MAN1=	pxz.1

MAKE_ENV+=	BINDIR=${PREFIX}/bin \
		MANDIR=${MANPREFIX}/man

MAKE_ARGS+=	CC="${CC}"

BROKEN_sparc64=	Does not link on sparc64

.include <bsd.port.mk>
