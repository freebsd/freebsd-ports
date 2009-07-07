# New ports collection makefile for: tclcl
# Date created:		23 April 1999
# Whom:			obonilla@fisicc-ufm.edu
#
# $FreeBSD$
#

PORTNAME=	tclcl
PORTVERSION=	1.19
PORTREVISION=	3
DISTVERSIONPREFIX=	src-
CATEGORIES=	devel tcl tk
MASTER_SITES=	SF/otcl-tclcl

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Tcl/C++ interface used by ns and nam

LIB_DEPENDS=	otcl:${PORTSDIR}/lang/otcl

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_XORG=	x11
USE_AUTOTOOLS=	autoconf:262
GNU_CONFIGURE=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	CHANGES.html TODO.html
.endif

.include <bsd.port.pre.mk>

# We have to link against the same Tcl/Tk version as OTcl does
.if exists(${LOCALBASE}/bin/otclsh)
OTCL_TCLVER!=	${ECHO_CMD} puts \$$tcl_version | ${LOCALBASE}/bin/otclsh
USE_TK=		${OTCL_TCLVER:S/.//}
.else
USE_TK=		82+
.endif

.include "${PORTSDIR}/Mk/bsd.tcl.mk"

CONFIGURE_ARGS=	--with-tcl-ver=${TCL_VER} --with-tk-ver=${TK_VER}

post-patch:
	@${REINPLACE_CMD} -e 's|exec tclsh|exec ${TCLSH}|g' ${WRKSRC}/otcldoc
	@${REINPLACE_CMD} -e 's|../lib/tcl$$TCL_HI_VERS|${TCL_LIBDIR}|g' \
		-e 's|../include|${TCL_INCLUDEDIR}/generic|g' ${WRKSRC}/conf/configure.in.tcl
	@${REINPLACE_CMD} -e 's|../lib/tk$$TK_HI_VERS|${TK_LIBDIR}|g' \
		-e 's|../include|${TK_INCLUDEDIR}/generic|g' ${WRKSRC}/conf/configure.in.tk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcl2c++ ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/otcldoc ${PREFIX}/bin
	${MKDIR} ${PREFIX}/include/tclcl
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/tclcl
	${INSTALL_DATA} ${WRKSRC}/libtclcl.a ${PREFIX}/lib
	@${LN} -sf ${PREFIX}/lib/libtclcl.a ${PREFIX}/lib/libTcl.a

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
