PORTNAME=	yosys-ghdl-plugin
PORTVERSION=	g20230930
PORTREVISION=	1
CATEGORIES=	cad

MAINTAINER=	nsonack@herrhotzenplotz.de
COMMENT=	GHDL synthesis plugin for yosys
WWW=		https://github.com/ghdl/ghdl-yosys-plugin

LICENSE=	GPLv3

BUILD_DEPENDS=	ghdl>0:cad/ghdl \
		yosys>0:cad/yosys
RUN_DEPENDS=	yosys>0:cad/yosys
LIB_DEPENDS=	libffi.so:devel/libffi \
		libghdl-5_0_1.so:cad/ghdl \
		libtcmalloc.so:devel/google-perftools

USES=		gmake readline tcl
USE_GITHUB=	yes
GH_ACCOUNT=	ghdl
GH_PROJECT=	ghdl-yosys-plugin
GH_TAGNAME=	d44a7bccdaa458ab3ec0ce83459410604bee6c60

MAKE_ENV+=	GHDL=${LOCALBASE}/bin/ghdl \
		YOSYS_CONFIG=${LOCALBASE}/bin/yosys-config

PLIST_FILES=	share/yosys/plugins/ghdl.so

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/share/yosys/plugins/ghdl.so

.include <bsd.port.mk>
