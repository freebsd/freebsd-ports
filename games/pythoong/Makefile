# New ports collection makefile for:	pythoong
# Date created:		24 July 2000
# Whom:			Maxim Sobolev
#
# $FreeBSD$
#

PORTNAME=	pythoong
PORTVERSION= 	0.99
CATEGORIES=	games gnome
MASTER_SITES=	http://perso.wanadoo.fr/christophe.cressend/tarballs/

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	xbmtopbm:${PORTSDIR}/graphics/netpbm
LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs
RUN_DEPENDS=	gnomecc:${PORTSDIR}/sysutils/gnomecontrolcenter

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
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
	@${PERL} -pi -e 's|-lpthread|-pthread|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/pixmaps|\$\(datadir\)/gnome/pixmaps|g ; \
		 s|\$\(localstatedir\)/games|\$\(datadir\)/gnome/games|g'

.include <bsd.port.mk>
