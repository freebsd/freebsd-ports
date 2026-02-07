PORTNAME=	expect
PORTVERSION=	5.45.4
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	lang tcl tk
MASTER_SITES=	SF/${PORTNAME}/Expect/${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Sophisticated scripter based on Tcl/Tk
WWW=		https://expect.sourceforge.net

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/license.terms

USES=		autoreconf tcl:tea,wrapper
USE_LDCONFIG=	${LOCALBASE}/lib/${DISTNAME}

MAKE_ENV+=	STRIPPROG=${STRIP_CMD}
TEST_TARGET=	test

SUB_FILES+=	pkg-message

WRKSRC=		${WRKDIR}/${DISTNAME}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

post-install:
	${LN} -sf ${DISTNAME}/lib${DISTNAME}.so \
		${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.1
	${LN} -sf lib${PORTNAME}.so.1 ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so

.include <bsd.port.mk>
