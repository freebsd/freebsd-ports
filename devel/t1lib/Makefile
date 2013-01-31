# Created by: Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	t1lib
PORTVERSION=	5.1.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SUNSITE
MASTER_SITE_SUBDIR=	libs/graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Type 1 font rasterization library for Unix/X11

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
ALL_TARGET=	without_doc
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	X11 DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG=	xaw
CONFIGURE_ARGS+=	--with-x
PLIST_SUB+=	X11=""
.else
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=	X11="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^LIBTOOL[ ]*=.*|LIBTOOL=${LIBTOOL}|g'
	@${REINPLACE_CMD} -e \
		'/ALLSUBDIRS/s|$$(DOCSUBDIRS)||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|_LT_CURRENT=.*$$|_LT_CURRENT=5|g' ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/t1lib_doc.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
