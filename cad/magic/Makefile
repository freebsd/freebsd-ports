PORTNAME=	magic
DISTVERSION=	8.3.570
CATEGORIES=	cad
MASTER_SITES=	http://opencircuitdesign.com/magic/archive/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interactive editor for VLSI layouts
WWW=		http://opencircuitdesign.com/magic/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	bash:shells/bash

USES=		gl gmake gnome localbase:ldflags python:build shebangfix \
		tar:tgz tk:tea xorg
USE_GL=		gl glu
USE_GNOME=	cairo
USE_XORG=	ice sm x11 xext xi xmu

SHEBANG_FILES=	scripts/preproc.py tcltk/ext2sim.sh.in tcltk/ext2spice.sh.in \
		tcltk/magic.sh.in

CONFIGURE_ARGS=	--enable-modular \
		--with-opengl # --enable-modular should fix build on 15, when failures were due to missing symbols defined in *.sym but not in code

ALL_TARGET=	tcllibrary

BINARY_ALIAS=	git=${FALSE} \
		python3=${PYTHON_CMD} # this is needed, see https://github.com/RTimothyEdwards/magic/issues/173#issuecomment-1200065429

DESKTOP_ENTRIES="Magic" "" "" "${PORTNAME}" "" ""

PORTSCOUT=	limit:^8\.

CONFIGURE_WRKSRC=	${WRKSRC}/scripts

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

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
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} database/database.h

post-install:
	@cd ${STAGEDIR}${PREFIX}/lib/magic/tcl && \
		${STRIP_CMD} magicexec magicdnull tclmagic.so

.include <bsd.port.post.mk>
