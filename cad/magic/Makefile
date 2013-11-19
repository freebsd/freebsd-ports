# Created by: swallace
# $FreeBSD$

PORTNAME=	magic
PORTVERSION=	7.5.233
CATEGORIES=	cad
MASTER_SITES=	http://opencircuitdesign.com/magic/archive/ \
		http://fossies.org/linux/misc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive editor for VLSI layouts

LICENSE=	BSD

LIB_DEPENDS=	libBLT25.so:${PORTSDIR}/x11-toolkits/blt

CONFIGURE_WRKSRC=	${WRKSRC}/scripts

USES+=		gmake tk:build
USE_XORG=	ice xext xi xmu
USE_GL=		gl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} --with-tk=${TK_LIBDIR}
ALL_TARGET=	tcllibrary

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DESKTOP_ENTRIES="Magic" "" "" "${PORTNAME}" "" ""

PORTSCOUT=	limit:^7\.

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|^#!.*|#!${AWK} -f|' ${WRKSRC}/ext2spice/spice2sim
	@${REINPLACE_CMD} -e \
		's|TCL_LIB_NAME=.*|TCL_LIB_NAME="tcl${TCL_VER:S/.//}"|g ; \
		 s|TK_LIB_NAME=.*|TK_LIB_NAME="tk${TK_VER:S/.//}"|g ; \
		 s|wish$${TK_VERSION}|${WISH:T}|g ; \
		 s|tclsh$${TK_VERSION}|${TCLSH:T}|g ; \
		 s|-l/usr/X11R6/include|-I${LOCALBASE}/include|g' ${CONFIGURE_WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/CFLAGS/s| -pg | |' ${WRKSRC}/tcltk/Makefile
	@${REINPLACE_CMD} -e \
		's|^#!.*|#!${TCLSH}|' ${WRKSRC}/tcltk/strip_reflibs.tcl
	@${REINPLACE_CMD} -e \
		's|^#!.*|#!${WISH}|' ${WRKSRC}/tcltk/tkshell.tcl

pre-build:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} database/database.h)

.include <bsd.port.post.mk>
