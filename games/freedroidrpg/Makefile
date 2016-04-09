# Created by: Travis Poppe <tlp@liquidx.org>
# $FreeBSD$

PORTNAME=	freedroidrpg
PORTVERSION=	0.16.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.osuosl.org/pub/freedroid/freedroidRPG-${PORTVERSION:R}/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${SF_NAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Modification of the classical Freedroid engine into an RPG

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_sparc64=	does not configure

GNU_CONFIGURE=	yes
USES=		jpeg gmake localbase lua:52+ python
USE_SDL=	sdl image gfx
CONFIGURE_ENV=	LUA_CFLAGS="-I${LUA_INCDIR}" LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER}"

SF_NAME=	freedroidRPG
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	NLS BACKTRACE OPENGL SOUND
OPTIONS_DEFAULT=BACKTRACE OPENGL SOUND
OPTIONS_SUB=	yes

BACKTRACE_DESC=	Use backtrace() to generate nice bug reports
BACKTRACE_USES=			execinfo
BACKTRACE_CONFIGURE_ENABLE=	backtrace
BACKTRACE_VARS=			STRIP= # empty

OPENGL_USE=			GL=gl
OPENGL_CONFIGURE_ENABLE=	opengl

SOUND_LIB_DEPENDS=		libvorbis.so:audio/libvorbis \
				libogg.so:audio/libogg
SOUND_CONFIGURE_ENABLE=		sound
SOUND_USE=			SDL=mixer
NLS_USES=			gettext
NLS_CONFIGURE_ENABLE=		nls

.include <bsd.port.mk>
