# New ports collection makefile for:    tavrasm
# Date created:                         12 December 2003
# Whom:                                 Wes Peters <wes@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tavrasm
PORTVERSION=	1.22
CATEGORIES=	devel
MASTER_SITES=	http://www.tavrasm.org/:0
DISTFILES=	${PORTNAME}${EXTRACT_SUFX}:0

MAINTAINER=	wes@FreeBSD.org
COMMENT=	Tom's AVR Assembler

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip
BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison

WRKSRC=		${WRKDIR}/tavrasm.122
BUILD_WRKSRC=	${WRKSRC}/src

AVR_INCLUDE=	${PREFIX}/include/avr

MAKEFILE=	makefile
USE_GMAKE=	yes
ALL_TARGET=	tavrasm

# Also get the include files and documentation from Atmel

MASTER_SITES+=	http://www.atmel.com/dyn/resources/prod_documents/:1
DISTFILES+=	ASM.ZIP:1

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@if ! (cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}${PORTNAME}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS});\
	then \
		exit 1; \
	fi
	@if ! (unzip -qoLa ${_DISTDIR}ASM.ZIP 'appnotes/*.inc' 'doc/*' -d ${WRKSRC});\
	then \
		exit 1; \
	fi

do-install:
	${MKDIR} ${DOCSDIR} ${AVR_INCLUDE}
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${INSTALL_WRKSRC}/doc/* ${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/appnotes/*.inc ${AVR_INCLUDE}

.include <bsd.port.mk>
