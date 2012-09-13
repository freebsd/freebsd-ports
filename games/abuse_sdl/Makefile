# $FreeBSD$

PORTNAME=	abuse_sdl
PORTVERSION=	0.8
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	GENTOO/distfiles \
		http://abuse.zoy.org/raw-attachment/wiki/download/
DISTNAME=	abuse-${DISTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	SDL port of the Abuse game engine

LICENSE=	GPLv2

USE_GNOME=	gnomehack
USE_GL=		gl
USE_SDL=	mixer sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-assetdir=${DATADIR} --enable-release
MAKE_JOBS_SAFE=	yes

MAN6=		abuse.6 abuse-tool.6

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/abuse \
		bin/abuse-tool \
		share/pixmaps/abuse.png

PORTDATA=	*
PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

.include <bsd.port.options.mk>

post-install:
# Pixmaps
	${INSTALL_DATA} ${WRKSRC}/doc/abuse.png ${PREFIX}/share/pixmaps/

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
