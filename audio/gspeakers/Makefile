# New ports collection makefile for:	gspeakers
# Date created:				10th December 2003
# Whom:					Vincent Tantardini <vinc@freebsd-fr.org>
#
# $FreeBSD$

PORTNAME=	gspeakers
PORTVERSION=	0.10.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnome-based loudspeaker design program

LIB_DEPENDS=	gtkmm:${PORTSDIR}/x11-toolkits/gtk--2
RUN_DEPENDS=	spice3:${PORTSDIR}/cad/spice

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack libxml2 gnomeprefix
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include" \
		LIBS="-L${X11BASE}/lib -L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e \
		"s,/share/pixmaps/,/share/gnome/pixmaps/${PORTNAME}/," \
		-e "s,/share/xml/,/share/gnome/xml/${PORTNAME}/," \
		${WRKSRC}/src/*.cc
	@${REINPLACE_CMD} -e \
		"s,/usr/local/share/xml/,${PREFIX}/share/gnome/xml/${PORTNAME}/,g" \
		${WRKSRC}/xml/*.xml

.include <bsd.port.mk>
