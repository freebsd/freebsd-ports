# ex:ts=8
# New ports collection makefile for:	libt1
# Date created:			13, May, 1999
# Whom:				Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	t1lib
PORTVERSION=	5.0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs/graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Type 1 Rasterizer Library for UNIX/X11

USE_GMAKE=	yes
USE_LIBTOOL_VER=	13
ALL_TARGET=	without_doc
INSTALLS_SHLIB=	yes

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
CONFIGURE_ARGS+=	--with-x
PLIST_SUB+=	X11=""
.else
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=	X11="@comment "
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/t1lib_doc.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
