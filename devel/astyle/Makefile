# Created by: Don Croyle <croyle@gelemna.org>
# $FreeBSD$

PORTNAME=	astyle
PORTVERSION=	2.06
CATEGORIES=	devel textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_linux

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Source code indenter and formatter for C, C++, C\#, and Java

LICENSE=	MIT
LICENSE_FILE=	${WRKDIR}/astyle/LICENSE.txt

ALL_TARGET=	astyle
LDFLAGS+=	-s
USES=		compiler gmake iconv

WRKSRC=		${WRKDIR}/astyle/build/${COMPILER_TYPE}

OPTIONS_DEFINE=	DOCS

pre-patch:
	@${REINPLACE_CMD} -e 's,\(CFLAGSr.*=.*\),\1 -I${LOCALBASE}/include,' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/astyle ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/astyle/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
