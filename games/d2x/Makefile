# New ports collection makefile for:	d2x
# Date created:		5 Apr 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	d2x
PORTVERSION=	0.2.5
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	http://offload2.icculus.org:9090/d2x/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unix port of Descent 2 Game

GNU_CONFIGURE=	yes
USE_SDL=	sdl image
USE_GMAKE=	yes

CONFIGURE_ARGS=	--disable-network --disable-debug

PORTDOCS=	README TODO NEWS AUTHORS readme.txt installation.txt
PLIST_FILES=	bin/d2x

.ifdef(WITH_OPENGL)
USE_GL=		glut
CONFIGURE_ARGS+=--with-opengl
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

pre-everything::
.ifndef(WITH_OPENGL)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define WITH_OPENGL to use OpenGL for 3D graphics"
	@${ECHO_MSG} ""
.endif

do-install:
.ifdef(WITH_OPENGL)
		${INSTALL} ${WRKSRC}/d2x-gl  ${PREFIX}/bin/d2x
.else
		${INSTALL} ${WRKSRC}/d2x-sdl ${PREFIX}/bin/d2x
.endif
.if !defined(NOPORTDOCS)
	        ${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	        ${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	        ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
