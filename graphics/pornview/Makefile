# New ports collection Makefile for: pornview
# Date created:		24 Nov 2002
# Whom:			Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pornview
PORTVERSION=	0.1.2.b
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/b/}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
#		xine.2:${PORTSDIR}/graphics/libxine

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include/" \
		LDFLAGS="-L${LOCALBASE}/lib"
#CONFIGURE_ARGS+=	--with-xine
USE_GNOMENG=	yes
USE_GNOME=	gtk12 gdkpixbuf gnomehier gnomeprefix
USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e 's,$(datadir)/gnome/apps/,$(datadir)/apps/,' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
