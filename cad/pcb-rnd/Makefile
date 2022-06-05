PORTNAME=	pcb-rnd
DISTVERSION=	3.0.4
CATEGORIES=	cad
MASTER_SITES=	http://repo.hu/projects/pcb-rnd/releases/

MAINTAINER=	fuz@fuz.su
COMMENT=	Flexible, modular Printed Circuit Board editor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfungw.so:devel/fungw \
		librnd-hid.so:cad/librnd \
		libfreetype.so:print/freetype2 \
		libgd.so:graphics/gd \
		libxml2.so:textproc/libxml2

USES=		gmake pkgconfig tar:bz2

HAS_CONFIGURE=	yes
BINARY_ALIAS=	make=${MAKE_CMD}

OPTIONS_DEFINE=	DOCS

pre-configure:
	${REINPLACE_CMD} \
	    -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
	    ${WRKSRC}/scconfig/src/sul/find_freetype2.c

.include <bsd.port.mk>
