# New ports collection makefile for:	osmose
# Date created:				27 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	osmose
PORTVERSION=	0.6.30
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav
DISTNAME=	${PORTNAME}-final-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sega Master System emulator

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	uses i386 assembly code
USE_DOS2UNIX=	yes
USE_ZIP=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
NO_WRKSUBDIR=	yes

OPTIONS=	OPTIMIZED_CFLAGS "Enable compilation optimizations" on

PLIST_FILES=	bin/osmose
PORTDOCS=	readme.txt

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	OPTIMIZED_CFLAGS=yes
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
