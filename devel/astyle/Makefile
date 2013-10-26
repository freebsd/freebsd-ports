# Created by: Don Croyle <croyle@gelemna.org>
# $FreeBSD$

PORTNAME=	astyle
PORTVERSION=	2.03
PORTREVISION=	1
CATEGORIES=	devel textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_linux

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Source code indenter and formatter for C, C++, C\#, and Java

ALL_TARGET=	astyle
CFLAGS+=	-W -Wall -fno-rtti -fno-exceptions
LDFLAGS+=	-s
MAKE_ARGS+=	CFLAGS="${CFLAGS}"
USES=		gmake
USE_GCC=	yes

WRKSRC=		${WRKDIR}/astyle/build/gcc

pre-patch:
	@${REINPLACE_CMD} -e 's,^CFLAGS,#CFLAGS,; s,g++,${CXX},;' ${WRKSRC}/Makefile

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/astyle ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/astyle/doc/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
