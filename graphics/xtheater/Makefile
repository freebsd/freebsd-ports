# ex:ts=8
# Ports collection makefile for:	xtheater
# Date created:			Jun 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xtheater
PORTVERSION=	1.0.0.p1
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Xtheater-${PORTVERSION:S/.p/-pre/}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		smpeg.1:${PORTSDIR}/graphics/smpeg

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_BZIP2=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_MESA=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		SDL_CONFIG="${SDL_CONFIG}"
CONFIGURE_ARGS=	--enable-gl

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]prefix[)]/Xtheater|(libdir)/Xtheater|g ; \
		 s|-release.*$$|-module -avoid-version|g'
	@${REINPLACE_CMD} -e 's|PREFIX/Xtheater|PREFIX/lib/Xtheater|g' \
		${WRKSRC}/Xtheater.conf
.for file in plugins/player/smpeg/glscreen.c plugins/player/wm/glscreen.c
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
