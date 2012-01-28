# New ports collection makefile for:	apngasm
# Date created:		02 May 2010
# Whom:			Anonymous <swell.k@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	apngasm
PORTVERSION=	2.5
DISTVERSIONSUFFIX=-src
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create Animated PNG from a sequence of files

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

NO_WRKSUBDIR=	yes

USE_ZIP=	yes
USE_DOS2UNIX=	yes

CPPFLAGS+=	`libpng-config --I_opts`
LDFLAGS+=	`libpng-config --ldflags`

PORTDOCS=	readme.txt
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

.if !defined(NO_SHARED)
LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png
.else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libpng.a:${PORTSDIR}/graphics/png
LDFLAGS+=	-static
.endif

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} ${PORTNAME}.c \
		-o ${PORTNAME} ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
