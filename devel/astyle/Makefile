# Created by: Don Croyle <croyle@gelemna.org>
# $FreeBSD$

PORTNAME=	astyle
PORTVERSION=	3.1
PORTREVISION=	2
CATEGORIES=	devel textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_linux

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Source code indenter and formatter for C, C++, C\#, and Java

LICENSE=	MIT
LICENSE_FILE=	${WRKDIR}/astyle/LICENSE.md

USES=		compiler:c++11-lang dos2unix gmake

ALL_TARGET=	astyle
DOS2UNIX_GLOB=	*.ini
WRKSRC=		${WRKDIR}/astyle/build/${CHOSEN_COMPILER_TYPE}

OPTIONS_DEFINE=	DOCS EXAMPLES

do-configure:
	@${REINPLACE_CMD} -e "s:%%CXX%%:${CXX}:" \
		${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/astyle ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/astyle/doc/* ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/astyle/file/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
