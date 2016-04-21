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

USES=		tcl:tea autoreconf
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--datadir=${DATADIR}
PLIST_SUB+=	EXPECT_VER=${PORTVERSION} \
		LIBEXPECT_VER=${LIBEXPECT_VER}
TEST_TARGET=	test

post-install:
	${LN} -sf expect${PORTVERSION}/libexpect${LIBEXPECT_VER}.so \
		${STAGEDIR}${PREFIX}/lib/libexpect.so.1
	${LN} -sf libexpect.so.1 ${STAGEDIR}${PREFIX}/lib/libexpect.so

.include <bsd.port.mk>
