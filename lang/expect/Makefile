# Created by: pst
# $FreeBSD$

PORTNAME=	expect
PORTVERSION=	5.45.3
CATEGORIES=	lang tcl tk
MASTER_SITES=	SF/expect/Expect/${PORTVERSION:R}
DISTNAME=	${PORTNAME}${PORTVERSION:R}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Sophisticated scripter based on Tcl/Tk

LIBEXPECT_VER=	${PORTVERSION:S/.//g}

WRKSRC=		${WRKDIR}/${DISTNAME}

USES=		tcl autoreconf
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared \
		--exec-prefix=${PREFIX} \
		--datadir=${DATADIR} \
		--with-tclconfig=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR}
CONFIGURE_ENV=	ac_cv_sys_long_file_names=yes
PLIST_SUB+=	EXPECT_VER=${PORTVERSION} \
		LIBEXPECT_VER=${LIBEXPECT_VER}

post-install:
	${LN} -sf expect${PORTVERSION}/libexpect${LIBEXPECT_VER}.so \
		${STAGEDIR}${PREFIX}/lib/libexpect.so.1
	${LN} -sf libexpect.so.1 \
		${STAGEDIR}${PREFIX}/lib/libexpect.so

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} test

.include <bsd.port.mk>
