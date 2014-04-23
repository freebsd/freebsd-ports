# Created by: Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	t1lib
PORTVERSION=	5.1.2
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SUNSITE/libs/graphics/ \
		http://www.skysmurf.nl/comp/FreeBSD/distfiles/

MAINTAINER=	freebsd@skysmurf.nl
COMMENT=	Type 1 font rasterization library for Unix/X11

LICENSE=	LGPL20

USES=		gmake
USE_AUTOTOOLS=	libtool
ALL_TARGET=	without_doc
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	X11 DOCS
OPTIONS_DEFAULT=	X11

OPTIONS_SUB=	yes
X11_USE=	XORG=xaw
X11_CONFIGURE_WITH=	x

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^LIBTOOL[ ]*=.*|LIBTOOL=${LIBTOOL}|g'
	@${REINPLACE_CMD} -e \
		'/ALLSUBDIRS/s|$$(DOCSUBDIRS)||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|_LT_CURRENT=.*$$|_LT_CURRENT=5|g' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/t1lib_doc.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
