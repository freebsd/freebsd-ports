PORTNAME=	pcb-rnd
DISTVERSION=	3.0.5
CATEGORIES=	cad
MASTER_SITES=	http://repo.hu/projects/pcb-rnd/releases/

MAINTAINER=	fuz@fuz.su
COMMENT=	Flexible, modular Printed Circuit Board editor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfungw.so:devel/fungw \
		libfreetype.so:print/freetype2 \
		libgd.so:graphics/gd \
		libgenht.so:devel/genht \
		librnd-hid.so:cad/librnd \
		libxml2.so:textproc/libxml2

USES=		gmake pkgconfig tar:bz2

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--cflags/libs/sul/freetype2="-I${LOCALBASE}/include/freetype2 -I${LOCALBASE}/include/freetype2/freetype" \
		--ldflags/libs/sul/freetype2=-L${LOCALBASE}/lib \
		${WITH_DEBUG:D--debug} \
		--CC=${CC} \
		--CFLAGS='${CFLAGS}' \
		--LDFLAGS='${LDFLAGS}'
BINARY_ALIAS=	make=${MAKE_CMD}

OPTIONS_DEFINE=	DOCS

post-install:
.for f in pcb-rnd txt2bxl bxl2txt gsch2pcb-rnd
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/$f
.endfor
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pcb-rnd/plugins/*.so

.include <bsd.port.mk>
