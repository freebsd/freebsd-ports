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

LIB_DEPENDS=	SDL-1.1.3:${PORTSDIR}/devel/sdl12

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_X_PREFIX=	yes
USE_GNOME=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		SDL_CONFIG="${SDL_CONFIG}" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${PERL} -pi -e "s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$$\(datadir\)/gnome/|\$$\(datadir\)/|g ; \
		 s|\$$\(datadir\)/aclocal|\$$\(prefix\)/share/aclocal|g ; \
		 s|\$$\(datadir\)/locale|\$$\(prefix\)/share/locale|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g'

post-configure:
	@${PERL} -pi -e 's|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
		${WRKSRC}/libtool

.include <bsd.port.mk>
