# New ports collection makefile for:	love
# Date created:		01 Aug 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	love
DISTVERSION=	0.3-2
CATEGORIES=	games devel
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open-source 2D game engine

LIB_DEPENDS=	IL.1:${PORTSDIR}/graphics/devil \
		physfs-1.0.1:${PORTSDIR}/devel/physfs \
		freetype.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer
USE_GL=		gl glu
USE_LUA=	5.1+

ALL_TARGET=	default

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/love lib/liblove.a

PORTDOCS=	*
PORTEXAMPLES=	*

post-patch:
	@${REINPLACE_CMD} -e 's|ILvoid|void|' ${WRKSRC}/src/opengl/Image.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/love ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bin/liblove.a ${PREFIX}/lib
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demos/*.love ${EXAMPLESDIR}
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in changes.txt readme.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
