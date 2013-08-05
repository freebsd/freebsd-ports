# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	dasm
PORTVERSION=	2.20.11
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}-dillon/${PORTNAME}-dillon/${PORTVERSION}

MAINTAINER=	uffe@uffe.org
COMMENT=	Macro assembler for 8-bit microprocessors including MOS 6502, MC6803

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

USES=	gmake

BUILD_WRKSRC=	${WRKSRC}/src
MAKE_ARGS=	CC="${CC}" LDFLAGS="${LDFLAGS}" CFLAGS="${CFLAGS}"

PORTDOCS=	*
PLIST_FILES=	bin/dasm \
		bin/ftohex

do-install:
.for filename in dasm ftohex
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${filename} ${PREFIX}/bin
.endfor

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
