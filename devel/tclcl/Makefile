# Created by: obonilla@fisicc-ufm.edu
# $FreeBSD$

PORTNAME=	tclcl
PORTVERSION=	1.20
DISTVERSIONPREFIX=	src-
CATEGORIES=	devel tcl tk
MASTER_SITES=	SF/otcl-${PORTNAME}/TclCL/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl/C++ interface used by ns and nam

LICENSE=	BSD

LIB_DEPENDS=	libotcl.so:${PORTSDIR}/lang/otcl

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_XORG=	x11
USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes
PORTDOCS=	CHANGES.html TODO.html

.include <bsd.port.options.mk>

# We have to link against the same Tcl/Tk version as OTcl does
.if exists(${LOCALBASE}/bin/otclsh)
OTCL_TCLVER!=	${ECHO_CMD} puts \$$tcl_version | ${LOCALBASE}/bin/otclsh
USES+=		tk:${OTCL_TCLVER:S/.//}
.else
USES+=		tk
.endif

CONFIGURE_ARGS=	--with-tcl-ver=${TCL_VER} --with-tk-ver=${TK_VER}

post-patch:
	@${REINPLACE_CMD} -e 's|exec tclsh|exec ${TCLSH}|g' ${WRKSRC}/otcldoc
	@${REINPLACE_CMD} -e 's|../lib/tcl$$TCL_HI_VERS|${TCL_LIBDIR}|g' \
		-e 's|../include|${TCL_INCLUDEDIR}/generic|g' ${WRKSRC}/conf/configure.in.tcl
	@${REINPLACE_CMD} -e 's|../lib/tk$$TK_HI_VERS|${TK_LIBDIR}|g' \
		-e 's|../include|${TK_INCLUDEDIR}/generic|g' ${WRKSRC}/conf/configure.in.tk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcl2c++ ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/otcldoc ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/include/tclcl
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/tclcl
	${INSTALL_DATA} ${WRKSRC}/libtclcl.a ${STAGEDIR}${PREFIX}/lib
	@${LN} -sf ${PREFIX}/lib/libtclcl.a ${STAGEDIR}${PREFIX}/lib/libTcl.a

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
