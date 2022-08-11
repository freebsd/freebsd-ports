PORTNAME=	Trf
PORTVERSION=	2.1.4
PORTREVISION=	3
CATEGORIES=	devel tcl
MASTER_SITES=	SF/tcltrf/tcltrf/${PORTVERSION}
PKGNAMEPREFIX=	tcl-
DISTNAME=	trf${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Data conversion, digests, compression, error-correction for Tcl

LICENSE=	Tcl_Trf_License
LICENSE_NAME=	Tcl Trf License
LICENSE_FILE=	${WRKSRC}/doc/license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

TEST_DEPENDS=	${LOCALBASE}/lib/Memchan2.3/libMemchan.so.1:devel/tcl-memchan

USES+=		tcl:tea tar:bzip2
USE_LDCONFIG=	${PREFIX}/lib/Trf
DDIR=		${PREFIX}/lib/tcl${TCL_VER}/Trf
CFLAGS+=	-Wall -Werror

MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}"

REINPLACE_ARGS=	-i ""
CONFIGURE_ARGS+=--enable-static-zlib --enable-static-bzlib \
		--enable-static-md5

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/Trf
	${INSTALL_DATA} ${WRKSRC}/libTrf${PORTVERSION}.so \
		${WRKSRC}/pkgIndex.tcl ${STAGEDIR}${PREFIX}/lib/Trf/
	for m in ${WRKSRC}/doc/man/*.n	;	\
	do	\
		${INSTALL_MAN} $$m ${STAGEDIR}${MANNPREFIX}/man/mann/ ;\
	done
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/Trf/libTrf${PORTVERSION}.so

do-test:
	cd ${WRKSRC} && ${SETENV} TCLLIBPATH="${WRKSRC}" ${TCLSH} \
		${FILESDIR}/alltests.tcl

PLIST_SUB+=	TCL_DVER=${TCL_VER:C/\.//} VER=${PORTVERSION}

.include <bsd.port.mk>
