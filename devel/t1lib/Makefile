# ex:ts=8
# New ports collection makefile for:	libt1
# Date created:			13, May, 1999
# Whom:				Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	t1lib
PORTVERSION=	5.0.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs/graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Type 1 Rasterizer Library for UNIX/X11

USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--without-x
.endif

# DOCS depends on LaTeX and LaTeX-babel module
#.if defined(NOPORTDOCS)
ALL_TARGET=	without_doc
#.else
#BUILD_DEPEND+=	${LOCALBASE}/bin/latex:${PORTSDIR}/print/latex
#.endif

.include <bsd.port.mk>
