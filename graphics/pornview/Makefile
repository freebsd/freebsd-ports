# New ports collection Makefile for: pornview
# Date created:		24 Nov 2002
# Whom:			Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pornview
PORTVERSION=	0.2.0.p.1
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p./pre/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PornView is an image viewer/manager

LIB_DEPENDS=	exif.10:${PORTSDIR}/graphics/libexif

USE_X_PREFIX=	yes
USE_GNOME=	gdkpixbuf gnomehack gnomeprefix
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if defined(WITH_LIBXINE)
LIB_DEPENDS+=	xine.9:${PORTSDIR}/multimedia/libxine
CONFIGURE_ARGS+=	--enable-xine
.elseif defined(WITH_MPLAYER)
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
CONFIGURE_ARGS+=	--enable-mplayer
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|INCLUDED_LIBINTL=yes|INCLUDED_LIBINTL=no|g ; \
		 s|\\[$$][{]top_builddir[}]/intl/libintl.a|-lintl|g ; \
		 s|[{]datadir[}]/locale|{prefix}/share/locale|g' ${WRKSRC}/configure

.include <bsd.port.mk>
