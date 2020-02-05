# Created by: pst
# $FreeBSD$

PORTNAME=	expect
PORTVERSION=	5.45.4
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	lang tcl tk
MASTER_SITES=	SF/${PORTNAME}/Expect/${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Sophisticated scripter based on Tcl/Tk

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/license.terms

USES=		tcl:tea autoreconf
USE_LDCONFIG=	${LOCALBASE}/lib/${DISTNAME}

WRKSRC=		${WRKDIR}/${DISTNAME}
PLIST_SUB+=	PORTVERSION=${PORTVERSION}
SUB_FILES+=	pkg-message
SUB_LIST+=	MANPREFIX=${MANPREFIX}
TEST_TARGET=	test

post-install:
	${LN} -sf ${DISTNAME}/lib${DISTNAME}.so \
		${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.1
	${LN} -sf lib${PORTNAME}.so.1 ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so

.include <bsd.port.mk>
