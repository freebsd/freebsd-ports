# New ports collection makefile for:	xmps
# Date created:				15 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmps
PORTVERSION=	0.2.0
CATEGORIES=	graphics gnome
MASTER_SITES=	http://xmps.sourceforge.net/sources/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	SDL-1.1.4:${PORTSDIR}/devel/sdl12

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs gdkpixbuf
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		SDL_CONFIG="${SDL_CONFIG}" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | xargs ${REINPLACE_CMD} -e \
		 's|-lpthread|${PTHREAD_LIBS}|g'

post-configure:
	@${REINPLACE_CMD} -e 's|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
		${WRKSRC}/libtool

.include <bsd.port.mk>
