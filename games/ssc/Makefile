# New ports collection makefile for: ssc
# Date created:		17 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	ssc
PORTVERSION=	0.8
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}x

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	An OpenGL arcade space shoot-em-up with interesting physics

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_SDL=	mixer sdl
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${X11BASE}/include" \
		LDFLAGS=-L${X11BASE}/lib
ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		Does not compile with gcc 3.4
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|SDL\/||g; s|/usr/local|${PREFIX}|g" \
		${WRKSRC}/src/*.h ${WRKSRC}/src/*.cc

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
