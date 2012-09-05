# $FreeBSD$

PORTNAME=	abuse_sdl
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	GENTOO/distfiles \
		http://abuse.zoy.org/raw-attachment/wiki/download/
DISTNAME=	abuse-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An SDL port of the Abuse game engine

CONFLICTS=	abuse-[0-9]*

USE_GNOME=	gnomehack
USE_GL=		gl
USE_SDL=	mixer sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-assetdir=${DATADIR} --enable-release
MAKE_JOBS_SAFE=	yes

MAN6=		abuse.6 abuse-tool.6

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
