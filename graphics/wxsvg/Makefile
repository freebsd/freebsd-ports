# New ports collection makefile for:	wxsvg
# Date created:		2006-01-08
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/graphics/wxsvg/Makefile,v 1.1 2006/09/22 01:48:33 ahze Exp $

PORTNAME=	wxsvg
DISTVERSION=	1.0.7
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library to create, manipulate, and render SVG files

LIB_DEPENDS+=	avformat.1:${PORTSDIR}/multimedia/ffmpeg

USE_BZIP2=	yes
USE_AUTOTOOLS=	automake:111
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-wx-config=${LOCALBASE}/bin/wxgtk2-2.8-config
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GNOME=	libartlgpl2
USE_GMAKE=	yes
USE_WX=		2.8
USE_AUTOTOOLS=	automake:111

post-patch:
	@cd ${WRKSRC} && \
		${TOUCH} -f NEWS INSTALL
	@${REINPLACE_CMD} -e 's|WX_CONFIG_NAME=wx-config|WX_CONFIG_NAME=${WX_CONFIG}|' \
		${WRKSRC}/*.m4

.include <bsd.port.mk>
