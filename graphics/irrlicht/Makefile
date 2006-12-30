# New ports collection makefile for:	irrlicht
# Date created:		2006-12-29
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	irrlicht
PORTVERSION=	1.2
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Lightning fast realtime 3d engine

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_XLIB=	yes
USE_LDCONFIG=	yes
MAKE_ENV+=	CXX="${CXX}"

BUILD_WRKSRC=	${WRKSRC}/source/Irrlicht
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

do-install:
	${MKDIR} ${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/include && \
		${INSTALL_DATA} *.h ${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lib/FreeBSD/libIrrlicht.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/lib/FreeBSD/libIrrlicht.so.1.2.0 ${PREFIX}/lib

post-install:
	@${ECHO} ${PKGMESSAGE}

.include <bsd.port.post.mk>
