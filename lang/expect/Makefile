# Created by: pst
# $FreeBSD$

PORTNAME=	expect
PORTVERSION=	5.45.4
PORTEPOCH=	1
CATEGORIES=	lang tcl tk
MASTER_SITES=	SF/expect/Expect/${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Sophisticated scripter based on Tcl/Tk

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/license.terms

WRKSRC=		${WRKDIR}/${DISTNAME}

USES=		tcl:tea autoreconf
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--datadir=${DATADIR}
PLIST_SUB+=	PORTVERSION=${PORTVERSION}
TEST_TARGET=	test

post-install:
	${LN} -sf expect${PORTVERSION}/libexpect${PORTVERSION}.so \
		${STAGEDIR}${PREFIX}/lib/libexpect.so.1
	${LN} -sf libexpect.so.1 ${STAGEDIR}${PREFIX}/lib/libexpect.so

.include <bsd.port.mk>
