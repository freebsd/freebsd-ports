# Created by: Don Croyle <croyle@gelemna.org>
# $FreeBSD$

PORTNAME=	astyle
PORTVERSION=	2.04
PORTREVISION=	1
CATEGORIES=	devel textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_linux

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Source code indenter and formatter for C, C++, C\#, and Java

LICENSE=	LGPL3

ALL_TARGET=	astyle
CFLAGS+=	-W -Wall -fno-rtti -fno-exceptions
LDFLAGS+=	-s
MAKE_ARGS+=	CFLAGS="${CFLAGS}"
USES=		compiler gmake iconv

WRKSRC=		${WRKDIR}/astyle/build/gcc

OPTIONS_DEFINE=	DOCS

pre-patch:
	@${REINPLACE_CMD} -e 's,^CFLAGS,#CFLAGS,; s,g++,${CXX},; \
		s,\(CFLAGSr.*=.*\),\1 -I${LOCALBASE}/include,' \
		${WRKSRC}/Makefile

do-install:
	${STRIP_CMD} ${WRKSRC}/bin/astyle
	${INSTALL_PROGRAM} ${WRKSRC}/bin/astyle ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/astyle/doc/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
