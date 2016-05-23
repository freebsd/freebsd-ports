# Created by: Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	t1lib
PORTVERSION=	5.1.2
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SUNSITE/libs/graphics/ \
		http://www.skysmurf.nl/comp/FreeBSD/distfiles/

MAINTAINER=	freebsd@skysmurf.nl
COMMENT=	Type 1 font rasterization library for Unix/X11

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/LGPL

USES=		cpe gmake libtool
GNU_CONFIGURE=	yes
ALL_TARGET=	without_doc
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	X11 DOCS
OPTIONS_DEFAULT=	X11

OPTIONS_SUB=	yes
X11_USE=	XORG=xaw
X11_CONFIGURE_WITH=	x

post-patch:
	@${REINPLACE_CMD} -e \
		'/ALLSUBDIRS/s|$$(DOCSUBDIRS)||g' ${WRKSRC}/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/t1lib_doc.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
