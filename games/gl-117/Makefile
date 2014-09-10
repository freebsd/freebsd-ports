# Created by: ijliao
# $FreeBSD$

PORTNAME=	gl-117
PORTVERSION=	1.3.2
DISTVERSIONSUFFIX=	-src
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/GL-117%20Source

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	OpenGL & SDL action flight simulator

USE_GL=		glut
USES=		tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-opengl-dir=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

DESKTOP_ENTRIES=	"GL-117" \
			"Action flight simulator" \
			"" \
			"gl-117" \
			"Game;ArcadeGame;" \
			false

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
	${INSTALL_MAN}	${WRKSRC}/doc/gl-117.6 ${STAGEDIR}${MANPREFIX}/man/man6
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/gl-117.pdf ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
