# New ports collection makefile for:	iStream
# Date created:				31 August 2009
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	istream
PORTVERSION=	0.10
CATEGORIES=	audio
MASTER_SITES=	http://www.jochen-baier.de/istream/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Internet radio player applet for GNOME Panel

USE_GMAKE=	yes
USE_GNOME=	gnomepanel
USE_GSTREAMER=	yes
USE_XORG=	xtst
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}c
CONFIGURE_ENV=	CPPFLAGS="`pkg-config --cflags libgnomeui-2.0`"
MAKE_JOBS_SAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|libdir)/bonobo|prefix)/libdata/bonobo|' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/libexec/istream|${PREFIX}/libexec/istream|' ${WRKSRC}/src/GNOME_istreamApplet.server.in

.include <bsd.port.mk>
