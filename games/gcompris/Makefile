# New ports collection makefile for:	gcompris
# Date created:				21 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gcompris
PORTVERSION= 	0.3.1
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/share/automake/install-sh:${PORTSDIR}/devel/automake
LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs
RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore \
		${X11BASE}/share/gnome/sounds/login.wav:${PORTSDIR}/audio/gnomeaudio

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

CONFIGURE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-extract:
	@${LN} -sf ${LOCALBASE}/share/automake/install-sh ${WRKSRC}/install-sh
	@${LN} -sf ${LOCALBASE}/share/automake/mkinstalldirs ${WRKSRC}/mkinstalldirs
	@${PERL} -pi -e 's|-lpthread|-pthread|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/pixmaps|\$\(datadir\)/gnome/pixmaps|g ; \
		 s|\$\(datadir\)/sounds|\$\(datadir\)/gnome/sounds|g ; \
		 s|\$\(localstatedir\)/games|\$\(datadir\)/gnome/games|g'

.include <bsd.port.mk>
