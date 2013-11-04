# Created by: chuckr
# $FreeBSD$

PORTNAME=	itcl
PORTVERSION=	3.4.1
PORTEPOCH=	1
CATEGORIES=	lang tcl
MASTER_SITES=	SF/incrtcl/%5BIncr%20Tcl_Tk%5D-source/3.4.1
DISTNAME=	itcl${PORTVERSION}

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	Object-oriented extension to Tcl [incr Tcl]

USE_TCL=	84+

USE_LDCONFIG=	${PREFIX}/lib/itcl${PORTVERSION:R}

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

GNU_CONFIGURE=	yes
CFLAGS+=	-I${TCL_INCLUDEDIR}/generic
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR} \
		--prefix=${PREFIX} \
		--exec-prefix=${PREFIX}
CONFIGURE_ENV+=	ac_cv_c_tclh=${TCL_INCLUDEDIR}/unix
PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		VERSION=${PORTVERSION:R} \
		MAJOR=${PORTVERSION:R:R} \
		SHORT=${PORTVERSION:R:S/.//}

MANCOMPRESSED=	no
MANN=		body.itcl class.itcl code.itcl configbody.itcl delete.itcl ensemble.itcl find.itcl \
		is.itcl itcl.itcl itclvars.itcl local.itcl scope.itcl
MAN3=		Itcl_RegisterC.3 Itcl_Stack.3 Itcl_Class.3 Itcl_List.3 Itcl_Object.3 Itcl_Preserve.3

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -E '/^includedir/s|/include|/include/itcl${PORTVERSION:R}|' \
	    ${WRKSRC}/${CONFIGURE_SCRIPT}

post-build test:
	cd ${WRKSRC} && ${SETENV} ITCL_LIBRARY=${WRKSRC}/library \
		${TCLSH} tests/all.tcl -load "load ./libitcl.so.1"

post-install:
	${LN} -sf ${PREFIX}/lib/${PORTNAME}${PORTVERSION:R}/libitcl.so.1 \
	    ${PREFIX}/lib/libitcl.so.${PORTVERSION:R:R}
	${LN} -sf ${PREFIX}/lib/${PORTNAME}${PORTVERSION:R}/libitcl.so.1 \
	    ${PREFIX}/lib/${PORTNAME}${PORTVERSION:R}/libitcl${PORTVERSION:R:S/.//}.so
	${LN} -sf ${PREFIX}/lib/${PORTNAME}${PORTVERSION:R}/libitcl.so.1 \
	    ${PREFIX}/lib/libitcl.so
.for FILE in ${MAN3}
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE:S/Itcl_//} ${PREFIX}/man/man3/${FILE}
.endfor

.include <bsd.port.post.mk>
