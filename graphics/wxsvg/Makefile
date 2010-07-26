# New ports collection makefile for:	wxsvg
# Date created:		2006-01-08
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/graphics/wxsvg/Makefile,v 1.1 2006/09/22 01:48:33 ahze Exp $

PORTNAME=	wxsvg
DISTVERSION=	1.0b7_2
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library to create, manipulate, and render SVG files

AUTOMAKE_ARGS=	--add-missing
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22 automake:15 autoconf:262
USE_GNOME=	libartlgpl2
USE_GMAKE=	yes
USE_WX=		2.6

post-patch:
	@cd ${WRKSRC} && \
		${TOUCH} -f README NEWS INSTALL
	@${REINPLACE_CMD} -e 's|WX_CONFIG_NAME=wx-config|WX_CONFIG_NAME=${WX_CONFIG}|' \
		${WRKSRC}/*.m4

pre-configure:
	@cd ${WRKSRC}; ${SETENV} ${AUTOMAKE_ENV} ${ACLOCAL} -I .; \
		${SETENV} ${SCRIPTS_ENV} ${LIBTOOLIZE} --automake

.include <bsd.port.mk>
