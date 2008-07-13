# New ports collection makefile for: ssc
# Date created:		17 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	ssc
PORTVERSION=	0.8
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}x

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OpenGL arcade space shoot-em-up with interesting physics

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

DEPRECATED=	abandoned upstream, needs gcc32 which is going to be removed
EXPIRATION_DATE=2008-08-15

USE_BZIP2=	yes
USE_GCC=	3.2
USE_GMAKE=	yes
USE_GL=		gl
USE_SDL=	mixer sdl
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS=-L${LOCALBASE}/lib
ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|SDL\/||g; s|/usr/local|${PREFIX}|g" \
		${WRKSRC}/src/*.h ${WRKSRC}/src/*.cc

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
