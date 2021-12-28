# Created by: swallace

PORTNAME=	magic
DISTVERSION=	8.3.245
CATEGORIES=	cad
MASTER_SITES=	http://opencircuitdesign.com/magic/archive/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interactive editor for VLSI layouts

LICENSE=	MIT
LICENSE_FILE=	${FILESDIR}/license.txt

LIB_DEPENDS=	libBLT25.so:x11-toolkits/blt \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	bash:shells/bash

USES=		gmake gnome gl localbase python:3.6+,build shebangfix tk:tea tar:tgz xorg
USE_GNOME=	cairo
USE_XORG=	ice x11 xext xi xmu
USE_GL=		gl glu

SHEBANG_FILES=	scripts/preproc.py tcltk/magic.sh.in tcltk/ext2sim.sh.in tcltk/ext2spice.sh.in

CONFIGURE_ARGS=	--with-opengl
CONFIGURE_WRKSRC=	${WRKSRC}/scripts

ALL_TARGET=	tcllibrary

CFLAGS+=	-Wno-return-type # workaround for https://github.com/RTimothyEdwards/magic/issues/67
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DESKTOP_ENTRIES="Magic" "" "" "${PORTNAME}" "" ""

PORTSCOUT=	limit:^8\.

post-patch:
	@${REINPLACE_CMD} -e \
		's|^#!.*|#!${AWK} -f|' ${WRKSRC}/ext2spice/spice2sim
	@${REINPLACE_CMD} -e \
		's|TCL_LIB_NAME=.*|TCL_LIB_NAME="tcl${TCL_VER:S/.//}"|g ; \
		 s|TK_LIB_NAME=.*|TK_LIB_NAME="tk${TK_VER:S/.//}"|g ; \
		 s|wish$${TK_VERSION}|${WISH:T}|g ; \
		 s|tclsh$${TK_VERSION}|${TCLSH:T}|g ; \
		 s|-l/usr/X11R6/include|-I${LOCALBASE}/include|g' \
	    ${CONFIGURE_WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|^#!.*|#!${TCLSH}|' ${WRKSRC}/tcltk/strip_reflibs.tcl
	@${REINPLACE_CMD} -e \
		's|^#!.*|#!${WISH}|' ${WRKSRC}/tcltk/tkshell.tcl

pre-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} database/database.h

post-install:
	@cd ${STAGEDIR}${PREFIX}/lib/magic/tcl && ${STRIP_CMD} magicexec magicdnull tclmagic.so

.include <bsd.port.mk>
