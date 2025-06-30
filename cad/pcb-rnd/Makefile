PORTNAME=	pcb-rnd
DISTVERSION=	3.1.6
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.repo.hu/projects/pcb-rnd/releases/

MAINTAINER=	hasdalcodes@gmail.com
COMMENT=	Flexible, modular Printed Circuit Board editor
WWW=		http://www.repo.hu/projects/pcb-rnd/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfungw.so:devel/fungw \
		libfreetype.so:print/freetype2 \
		libgd.so:graphics/gd \
		libgenht.so:devel/genht \
		librnd-hid.so:cad/librnd

USES=		gmake gnome pkgconfig tar:bz2
USE_GNOME=	libxml2

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--cflags/libs/sul/freetype2="-I${LOCALBASE}/include/freetype2 -I${LOCALBASE}/include/freetype2/freetype" \
		--ldflags/libs/sul/freetype2=-L${LOCALBASE}/lib \
		${WITH_DEBUG:D--debug} \
		--CC=${CC} \
		--CFLAGS='${CFLAGS}' \
		--LDFLAGS='${LDFLAGS}'

TEST_TARGET=	test

BINARY_ALIAS=	make=${MAKE_CMD}

OPTIONS_DEFINE=	DOCS

TESTING_UNSAFE=	yes # ld: error: unable to find library -lrnd-3rd

post-patch:
	@${ECHO_CMD} 'USER_CFLAGS += -DSCCONFIG_ACCEPT_IMPLICIT' \
		>> ${WRKSRC}/scconfig/Makefile

post-install:
.for f in bxl2txt gsch2pcb-rnd pcb-rnd txt2bxl
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/$f
.endfor
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pcb-rnd/plugins/*.so

.include <bsd.port.mk>
